/// \file vector2D.cpp

#include "vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Vector2D::Vector2D() {};

	Vector2D::Vector2D(double newX, double newY) : x(newX), y(newY) {}

	Vector2D Vector2D::operator+(const Vector2D &other) const {
		return Vector2D(x + other.x, y + other.y);
	}

	void Vector2D::operator=(const Vector2D &other) {
		x = other.x;
		y = other.y;
	}

	void Vector2D::operator+=(const Vector2D &other) {
		x += other.x;
		y += other.y;
	}

	Vector2D Vector2D::operator*(double factor) const {
		return Vector2D(x * factor, y * factor);
	}

	void Vector2D::operator*=(double factor) {
		x *= factor;
		y *= factor;
	}

	ostream& operator<<(ostream& stream, Vector2D& vector) {
		stream << "(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

}