
#include "vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Vector2D::Vector2D() {};

	Vector2D::Vector2D(double newX, double newY) : x(newX), y(newY) {}

	Vector2D Vector2D::operator+(const Vector2D &other) {
		return Vector2D(x + other.x, y + other.y);
	}

	void Vector2D::operator=(const Vector2D &other) {
		x = other.x;
		y = other.y;
	}

	ostream& operator<<(ostream& stream, Vector2D& vector) {
		stream << "(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

}