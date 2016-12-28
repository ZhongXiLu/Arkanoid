/// \file ball.cpp

#include "ball.h"
#include "../wall/wall.h"
#include "../block/block.h"
#include "../../math/vector2D.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

namespace arkanoid {

	Ball::Ball() : notMoving(true), random(Random::getInstance()) {}

	Ball::Ball(double x, double y, double newSpeed, pair<double, double> size) : velocity(newSpeed, -newSpeed), origin(x,y), speed(newSpeed), notMoving(true), spedUp(false), random(Random::getInstance()), Entity(x, y, size) {}

	Ball::~Ball() {}

	void Ball::update() {}

	void Ball::draw() const {}

	void Ball::speedUp(double factor) {
		if(!spedUp) {
			velocity *= factor;
			spedUp = true;
		}
	}

	void Ball::setInvisible(double period) {
		invisDuration = period;
	}

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

		return collisions;
	}

	// Prevent linker errors
	template vector<int> Ball::bounceIfPossible<Block>(vector<unique_ptr<Block>> const &entities);
	template vector<int> Ball::bounceIfPossible<Wall>(vector<unique_ptr<Wall>> const &entities);

	void Ball::bounceIfPossible(unique_ptr<Player> const &player) {

		if(collidesWith(*player) && !notMoving) {

			const double maxPlayerPos = player->getPosition().x + player->getSize().first;
			const double playerLength = maxPlayerPos - player->getPosition().x;
			const double halfLength = playerLength / 2;
			const double centerPlayer = maxPlayerPos - (playerLength / 2);

			double collisionPoint = position.x + (size.first / 2);
			// Check if Ball is not outside the Players surface
			if(collisionPoint > maxPlayerPos) {
				collisionPoint = maxPlayerPos;
			} else if(collisionPoint < player->getPosition().x) {
				collisionPoint = player->getPosition().x;
			}
			const double relativeCollision = collisionPoint - player->getPosition().x;

			double ratio = 0.0;		// how much the Ball is located towards the edge
			double angle = 0.0;
			if(collisionPoint > centerPlayer) {
				// right half of the player
				ratio = (relativeCollision - halfLength) / halfLength;
				angle = 90.0 - (ratio * 70.0);		// maximum angle = 70°

			} else {
				// left half of the player
				ratio = (halfLength - relativeCollision) / halfLength;
				angle = 90.0 + (ratio * 70.0);		// maximum angle = 70°

			}

			velocity.x = speed * cos((angle + random->randomDouble(-5, 5)) * (M_PI/180));
			velocity.y = -1 * speed * sin((angle + random->randomDouble(-5, 5)) * (M_PI/180));

			// Reset flags (from hitting a block)
			spedUp = false;

		}
	}

	void Ball::reset() {
		position = origin;
		velocity.x = speed;
		velocity.y = -speed;
		notMoving = true;
		invisDuration = 0;
		spedUp = false;
	}

}