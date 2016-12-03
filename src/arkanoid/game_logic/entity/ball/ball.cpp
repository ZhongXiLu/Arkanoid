
#include "ball.h"
#include "../../math/vector2D.h"

#include <iostream>
#include <cmath>

using namespace std;

namespace arkanoid {

	Ball::Ball() {}

	Ball::Ball(double x, double y, double speed, pair<double, double> size) : velocity(speed, -speed), Entity(x, y, size) {}

	Ball::~Ball() {}

	void Ball::update() {
		// ...
	}

	void Ball::draw() const {
		// ...
	}

	void Ball::bounce(unique_ptr<Entity> const &other) {

		// Calculate the gaps between the Entities on all sides
		const double gapRight = abs((position.x + size.first) - other->getPosition().x);
		const double gapLeft = abs(position.x - (other->getPosition().x + other->getSize().first));
		const double gapTop = abs(position.y - (other->getPosition().y + other->getSize().second));
		const double gapBottom = abs((position.y + size.second) - other->getPosition().y);

		// Determine the smallest gaps, both horiztontally and vertically
		const double minGapHor = min(gapRight, gapLeft);
		const double minGapVer = min(gapTop, gapBottom);

		// Change the Ball 's direction based on the calculation above
		if(minGapHor < minGapVer) {
			// Ball was coming from Right/Left
			velocity.x *= -1;
		} else {
			// Ball was coming from Top/Bottom
			velocity.y *= -1;
		}
	
	}

}