
#include "player.h"
#include "../math/vector2D.h"

#include <iostream>

using namespace std;

Player::Player() : playerPos(0, 0) {}

Player::Player(int x, int y) : playerPos(x, y) {}

Vector2D Player::getPos() const {
	return playerPos;
}

bool Player::move(Vector2D newPos) {

	// TBI: Check if new playerPos is in Grid.

	playerPos = playerPos + newPos;

	return true;
}