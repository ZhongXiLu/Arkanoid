
#include "world.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	World::World() {}

	World::~World() {}

	void World::update() {
		
		// Update Ball + Check if there are collisions on the Ball
		ball->bounceIfPossible<Wall>(walls);
		
		vector<int> collisions = std::move(ball->bounceIfPossible<Block>(blocks));
		// Destroy all the Blocks that collided
		int blocksDeleted = 0;
		for(auto c: collisions) {
			blocks[c]->effectBall(ball);
			blocks.erase(blocks.begin() + c - blocksDeleted);
			blocksDeleted++;
		}
		
		ball->bounceIfPossible(player);

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
		if(ball->getPosition().y > 7 || ball->getPosition().y < 0 ||
			ball->getPosition().x > 9 || ball->getPosition().x < 0) {
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

}