
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

	bool Entity::collidesWith(unique_ptr<Entity> const &other) const {

		if(
			// Check if left/right is in other's surface
			position.x <= other->getPosition().x + other->getSize().first
			&& position.x + getSize().first >= other->getPosition().x
			
			// Check if top/bottom is in other's surface
			&& position.y <= other->getPosition().y + other->getSize().second
			&& position.y + getSize().second >= other->getPosition().y
		) {
			return true;
		}

		return false;
	}
}