
#include "entity.h"
#include "../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	Entity::Entity() : playerPos(0.0, 0.0) {}

	Entity::Entity(double x, double y) : playerPos(x, y) {}

	Vector2D Entity::getPos() const {
		return playerPos;
	}

}