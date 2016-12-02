
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
		for(auto &e: entities) {
			e->update();
			if(ball->intersectsWith(e)) {
				// cout << "intersecting" << endl;
			}
		}
		ball->update();

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