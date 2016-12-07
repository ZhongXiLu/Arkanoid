
#include "ball.h"
#include "../wall/wall.h"
#include "../../math/vector2D.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

namespace arkanoid {

	Ball::Ball() {}

	Ball::Ball(double x, double y, double speed, pair<double, double> size) : velocity(speed, -speed), origin(x, y), Entity(x, y, size) {}

	Ball::~Ball() {}

	void Ball::update() {}

	void Ball::draw() const {}

	template<typename T>
	vector<int> Ball::bounceIfPossible(vector<unique_ptr<T>> const &entities) {

		// Check for every Entity if there's a collision
		vector<int> collisions;		// At most 2 collisions
		for(int e = 0; e < entities.size(); e++) {
			if(collidesWith(*entities[e])) {
				collisions.push_back(e);
			}
		}

		if(!collisions.empty()) {
			if(collisions.size() == 2) { 
				// Use procedure for two Entities:
				// If two collided Entities are on top of each other:
				//		-> Ball was coming from left/right
				// Oterwise: Ball was coming from top/left
				if(entities[collisions[0]]->getPosition().x == entities[collisions[1]]->getPosition().x) {
					// Ball coming from left/right
					velocity.x *= -1;
				} else {
					// Ball coming from top/bottom
					velocity.y *= -1;
				}
			} else {
				// Use procedure for one Entity

				// Calculate the gaps between the Ball and the collided Entity on all sides
				const double gapRight = abs((position.x + size.first) - entities[collisions[0]]->getPosition().x);
				const double gapLeft = abs(position.x - (entities[collisions[0]]->getPosition().x + entities[collisions[0]]->getSize().first));
				const double gapTop = abs(position.y - (entities[collisions[0]]->getPosition().y + entities[collisions[0]]->getSize().second));
				const double gapBottom = abs((position.y + size.second) - entities[collisions[0]]->getPosition().y);

				// Determine the smallest gaps, both horiztontally and vertically
				const double minGapHor = min(gapRight, gapLeft);
				const double minGapVer = min(gapTop, gapBottom);

				if(!(abs(minGapHor - minGapVer) < 0.01) && !(minGapVer < 0.001 || minGapHor < 0.001)) {
					// Change the Ball 's direction based on the calculation above
					if(minGapHor < minGapVer) {
						// Ball coming from left/right
						velocity.x *= -1;
					} else {
						// Ball coming from top/bottom
						velocity.y *= -1;
					}
				}
			}
		}

		return collisions;
	}

	// Prevent linker errors
	template vector<int> Ball::bounceIfPossible<Entity>(vector<unique_ptr<Entity>> const &entities);
	template vector<int> Ball::bounceIfPossible<Wall>(vector<unique_ptr<Wall>> const &entities);

	// *** TBI
	void Ball::bounceIfPossible(unique_ptr<Player> const &player) {

		if(collidesWith(*player)) {

			// Calculate the gaps between the Ball and the collided Entity on all sides
			const double gapRight = abs((position.x + size.first) - player->getPosition().x);
			const double gapLeft = abs(position.x - (player->getPosition().x + player->getSize().first));
			const double gapTop = abs(position.y - (player->getPosition().y + player->getSize().second));
			const double gapBottom = abs((position.y + size.second) - player->getPosition().y);

			// Determine the smallest gaps, both horiztontally and vertically
			const double minGapHor = min(gapRight, gapLeft);
			const double minGapVer = min(gapTop, gapBottom);

			if(!(abs(minGapHor - minGapVer) < 0.01) && !(minGapVer < 0.001 || minGapHor < 0.001)) {
				// Change the Ball 's direction based on the calculation above
				if(minGapHor < minGapVer) {
					// Ball coming from left/right
					velocity.x *= -1;
				} else {
					// Ball coming from top/bottom
					velocity.y *= -1;
				}
			}

		}
	}

	void Ball::reset() {
		position = origin;
		velocity.x = abs(velocity.x);
		velocity.y = -1*abs(velocity.y);
	}

}