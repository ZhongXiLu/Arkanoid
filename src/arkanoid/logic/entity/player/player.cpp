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
		if(speedUpDuration == 0) {
			// Prevent multiple speed ups
			speed *= factor;
			speedUpDuration = 180;	// 180 frames = 3 seconds
		}
	}

	void Player::reset() {
		speed = originalSpeed;
		position = origin;
		notMoving = true;
		speedUpDuration = 0;
	}
	
}