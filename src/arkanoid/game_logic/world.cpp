
#include "world.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	World::World() {
		// ...
	}

	World::~World() {
		for(auto e: entities) {
			delete e;
		}
	}

	void World::update() {
		for(auto e: entities) {
			e->update();
		}
	}

	void World::addEntity(arkanoid::Entity* entity) {
		entities.push_back(entity);
	}


}