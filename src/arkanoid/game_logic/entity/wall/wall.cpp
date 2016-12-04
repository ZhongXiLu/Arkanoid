
#include "wall.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Wall::Wall() {}

	Wall::Wall(double x, double y, pair<double, double> size) : Entity(x, y, size) {}

	Wall::~Wall() {}

	void Wall::update() {}

	void Wall::draw() const {}
	
}