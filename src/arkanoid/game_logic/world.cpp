
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
		
		vector<int> collisions = std::move(ball->bounceIfPossible<Entity>(entities));
		// Destroy all the Entities that collided
		int entitiesDeleted = 0;
		for(auto c: collisions) {
			entities.erase(entities.begin() + c - entitiesDeleted);
			entitiesDeleted++;
		}
		
		ball->bounceIfPossible(player);		// TBI: player bounce algorithm

		// Update all Entities
		for(auto &e: entities) {
			e->update();
		}
		for(auto &w: walls) {
			w->update();
		}
		ball->update();
		player->update();

		// Check if Ball has been missed
		if(ball->getPosition().y > 7) {
			player->reset();
			ball->reset();
		}

	}

	void World::draw() const {
		for(const auto &e: entities) {
			e->draw();
		}
		ball->draw();
		player->draw();
		for(const auto &w: walls) {
			w->draw();
		}
	}

	void World::addEntity(unique_ptr<arkanoid::Entity> entity) {
		entities.push_back(std::move(entity));
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