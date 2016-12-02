
#include "ball.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Ball::Ball() {}

	Ball::Ball(double x, double y, double speed, pair<double, double> size) : velocity(-speed, -speed), Entity(x, y, size) {}

	Ball::~Ball() {}

	void Ball::update() {
		// ...
	}

	void Ball::draw() const {
		// ...
	}

}