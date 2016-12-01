
#include "player.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Player::Player() : Entity(0.0, 0.0) {}

	Player::Player(double x, double y, double newSpeed) : velocity(newSpeed, 0), speed(newSpeed), Entity(x, y) {}

	Player::~Player() {}

	void Player::update() {
		// ...
	}
	
}