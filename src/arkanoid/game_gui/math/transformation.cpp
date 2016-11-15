
#include "transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	Transformation::Transformation() {}

	Transformation::Transformation(double gridWidth, double gridHeight, double windowWidth, double windowHeight)
	: widthScale(windowWidth/gridWidth), heightScale(windowHeight/gridHeight), maxWindowHeight(windowHeight) {}

	arkanoid::Vector2D Transformation::toGrid(const sf::Vector2f &vector) {
		return arkanoid::Vector2D(vector.x / widthScale, maxWindowHeight - (vector.y / heightScale));
	}

}