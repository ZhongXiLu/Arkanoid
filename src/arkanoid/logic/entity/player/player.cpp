/// \file player.cpp

#include "player.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Player::Player() {}

	Player::Player(double x, double y, double newSpeed, pair<double, double> size) : velocity(newSpeed, 0), speed(newSpeed), origin(x, y), originalSpeed(newSpeed), notMoving(true), Entity(x, y, size) {}

	Player::~Player() {}

	void Player::update() {}

	void Player::draw() const {}

	void Player::speedUp(double factor) {
		if(effectDuration == 0) {
			// Prevent multiple speed ups
			speed *= factor;
		}
		effectDuration = 180;	///< 5 seconds
	}

	void Player::reset() {
		position = origin;
		notMoving = true;
		effectDuration = 0;
	}
	
}