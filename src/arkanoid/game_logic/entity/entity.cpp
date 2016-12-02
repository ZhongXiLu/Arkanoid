
#include "entity.h"
#include "../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	Entity::Entity() {}

	Entity::Entity(double x, double y, pair<double, double> newSize) : position(x, y), size(newSize) {}

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

	void Entity::setSize(pair<double, double> newSize) {
		size = newSize;
	}

	pair<double, double> Entity::getSize() const {
		return size;
	}
}