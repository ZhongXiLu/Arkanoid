
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

	bool Entity::intersectsWith(unique_ptr<Entity> const &other) const {

		// Calcluate edges of the Entities
		const double thisMinX = position.x;
		const double thisMaxX = position.x + getSize().first;
		const double thisMinY = position.y;
		const double thisMaxY = position.y - getSize().second;

		const double otherMinX = other->getPosition().x;
		const double otherMaxX = other->getPosition().x + other->getSize().first;
		const double otherMinY = other->getPosition().y;
		const double otherMaxY = other->getPosition().y + other->getSize().second;

		if(
			(	// Check if left/right is in other's surface
				(thisMaxX >= otherMinX && thisMaxX <= otherMaxX)
				|| (thisMinX >= otherMinX && thisMinX <= otherMaxX)
			)
			&&
			(	// Check if top/bottom is in other's surface
				(thisMaxY >= otherMinY && thisMaxY <= otherMaxY)
				|| (thisMinY >= otherMinY && thisMinY <= otherMaxY)
			)
		) {
			return true;
		}

		return false;
	}
}