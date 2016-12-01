
#include "wall.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Wall::Wall() : Entity(0.0, 0.0) {}

	Wall::Wall(double x, double y) : Entity(x, y) {}

	Wall::~Wall() {}

	void Wall::update() {
		// ...
	}

	void Wall::draw() const {
		// ...
	}
}