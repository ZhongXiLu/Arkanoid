/// \file world.cpp

#include "world.h"
#include "entity/block/special_block/ball_speed_block.h"
#include "entity/block/special_block/player_speed_block.h"
#include "entity/block/special_block/invis_block.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	constexpr double gridW = 9.0;
	constexpr double gridH = 7.0;

	World::World() {}

	World::~World() {}

	void World::checkCollisions() {
		// Update Ball + Check if there are collisions on the Ball
		ball->bounceIfPossible<Wall>(walls);
		
		vector<int> collisions = std::move(ball->bounceIfPossible<Block>(blocks));
		// Destroy all the Blocks that collided
		int blocksDeleted = 0;
		for(auto c: collisions) {

			// Check if it's a special Block
			BallSpeedBlock* ballSpeedBlock = dynamic_cast<BallSpeedBlock*>((blocks[c - blocksDeleted]).get());
			if(ballSpeedBlock) {
				ballSpeedBlock->effectBall(ball);
			}
			InvisBlock* invisBlock = dynamic_cast<InvisBlock*>((blocks[c - blocksDeleted]).get());
			if(invisBlock) {
				invisBlock->effectBall(ball);
			}
			PlayerSpeedBlock* playerSpeedBlock = dynamic_cast<PlayerSpeedBlock*>((blocks[c - blocksDeleted]).get());
			if(playerSpeedBlock) {
				playerSpeedBlock->effectPlayer(player);
			}

			blocks.erase(blocks.begin() + c - blocksDeleted);
			blocksDeleted++;
		}
		
		ball->bounceIfPossible(player);
	}

	void World::update() {
		checkCollisions();

		// Update all Entities
		for(auto &b: blocks) {
			b->update();
		}
		for(auto &w: walls) {
			w->update();
		}
		ball->update();
		player->update();

		// Check if Ball has been missed (or out of the world for some reason)
		if(ball->getPosition().y > gridH || ball->getPosition().y < 0 ||
			ball->getPosition().x > gridW || ball->getPosition().x < 0) {
			player->reset();
			ball->reset();
		}

	}

	void World::draw() const {
		for(const auto &b: blocks) {
			b->draw();
		}
		ball->draw();
		player->draw();
		for(const auto &w: walls) {
			w->draw();
		}
	}

	void World::addBlock(unique_ptr<arkanoid::Block> block) {
		blocks.push_back(std::move(block));
	}

	void World::addWall(unique_ptr<arkanoid::Wall> wall) {
		walls.push_back(std::move(wall));
	}

	void World::setBall(unique_ptr<arkanoid::Ball> newBall) {
		ball = std::move(newBall);
	}

	void World::setPlayer(unique_ptr<arkanoid::Player> newPlayer) {
		player = std::move(newPlayer);
	}

	bool World::levelEnded() const {
		return blocks.size() == 0;
	}

}