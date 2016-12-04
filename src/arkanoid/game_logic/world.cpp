
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
		ball->update();
		ball->bounce(entities);

		// Update all Entities
		for(int i = 0; i < entities.size(); i++) {
			entities[i]->update();
		}

	}

	void World::draw() const {
		for(const auto &e: entities) {
			e->draw();
		}
		ball->draw();
	}

	void World::addEntity(unique_ptr<arkanoid::Entity> entity) {
		entities.push_back(std::move(entity));
	}

	void World::setBall(unique_ptr<arkanoid::Ball> newBall) {
		ball = std::move(newBall);
	}

}