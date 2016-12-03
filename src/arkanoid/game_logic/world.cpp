
#include "world.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	World::World() {}

	World::~World() {}

	void World::update() {
		
		// Update all Entities + Balls
		// And check for collision
				ball->update();

		bool ballHasCollided = false;		// Prevent multiple bounces in one frame
		for(auto &e: entities) {
			e->update();
			if(!ballHasCollided && ball->collidesWith(e)) {
				ball->bounce(e);
				ballHasCollided = true;
			}
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