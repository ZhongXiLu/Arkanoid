
#include "ball.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Ball::Ball() : Entity(0.0, 0.0) {}

	Ball::Ball(double x, double y, double speed) : velocity(-speed, -speed), Entity(x, y) {}

	Ball::~Ball() {}

	void Ball::update() {
		position = position + velocity;
	}

}