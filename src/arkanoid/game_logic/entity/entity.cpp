
#include "entity.h"
#include "../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	Entity::Entity() : position(0.0, 0.0) {}

	Entity::Entity(double x, double y) : position(x, y) {}

	Vector2D Entity::getPosition() const {
		return position;
	}

	void Entity::setPosition(double x, double y) {
		position.x = x;
		position.y = y;
	}

	void Entity::setPosition(const Vector2D &vector) {
		position = vector;
	}

}