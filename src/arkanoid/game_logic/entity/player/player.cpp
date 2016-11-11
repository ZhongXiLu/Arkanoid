
#include "player.h"
#include "../math/vector2D.h"

#include <iostream>

using namespace std;

Player::Player() : Entity(0, 0) {}

Player::Player(int x, int y) : Entity(x, y) {}

bool Player::move(Vector2D &newPos) {

	// TBI: Check if new playerPos is in Grid.
	playerPos = playerPos + newPos;

	return true;
}

bool Player::moveLeft() {
	Vector2D left(-1, 0);
	if(move(left)) {
		return true;
	}
	return false;
}

bool Player::moveRight() {
	Vector2D right(1, 0);
	if(move(right)) {
		return true;
	}
	return false;
}