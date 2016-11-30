
#include "ball.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Ball::Ball() : speed(5), Entity(0.0, 0.0) {
		Vector2D v(-speed, -speed);
		velocity = v;
	}

	Ball::Ball(double x, double y) : speed(5), Entity(x, y) {
		Vector2D v(-speed, -speed);
		velocity = v;
	}

	Ball::~Ball() {}

	void Ball::update() {
		position = position + velocity;
	}

}