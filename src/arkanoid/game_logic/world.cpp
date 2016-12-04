
#include "world.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	World::World() {}

	World::~World() {}

	void World::update() {
		
		// Update Ball + Check if there are collisions on the Ball
		ball->bounce(entities);
		ball->bounce(player);		// TBI: player bounce algorithm

		// Update all Entities
		for(int i = 0; i < entities.size(); i++) {
			entities[i]->update();
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
	}

	void World::addEntity(unique_ptr<arkanoid::Entity> entity) {
		entities.push_back(std::move(entity));
	}

	void World::setBall(unique_ptr<arkanoid::Ball> newBall) {
		ball = std::move(newBall);
	}

	void World::setPlayer(unique_ptr<arkanoid::Player> newPlayer) {
		player = std::move(newPlayer);
	}

}