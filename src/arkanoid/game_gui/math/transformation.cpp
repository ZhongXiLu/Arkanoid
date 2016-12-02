
#include "transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	Transformation::Transformation() {}

	Transformation::Transformation(double gridWidth, double gridHeight, double windowWidth, double windowHeight)
	: widthScale(windowWidth/gridWidth), heightScale(windowHeight/gridHeight) {}

	arkanoid::Vector2D Transformation::convertVector(const sf::Vector2f &vector) {
		return arkanoid::Vector2D(vector.x / widthScale, vector.y / heightScale);
	}

	double Transformation::convertX(double x) {
		return x / widthScale;
	}

	double Transformation::convertY(double y) {
		return  y / heightScale;
	}

}