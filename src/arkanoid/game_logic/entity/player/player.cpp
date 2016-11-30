
#include "player.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Player::Player() : Entity(0.0, 0.0) {}

	Player::Player(double x, double y) : Entity(x, y) {}

	Player::~Player() {}

	void Player::update() {
		// ...
	}

	bool Player::move(double x, double y) {

		// TBI: Check if new position is in Grid.

		// cout << "moving player from " << position;
		position.x += x;
		position.y += y;
		// cout << " to " << position << endl;

		return true;
	}
	
}