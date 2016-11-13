
#include "../../arkanoid.h"		// GLOBAL VARIABLES (SCREEN::WIDTH, GRID::WIDTH, ...)
#include "transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	Transformation::Transformation() {}

	Transformation::Transformation(int gridWidth, int gridHeight, int windowWidth, int windowHeight)
	: widthScale(windowWidth/gridWidth), heightScale(windowHeight/gridHeight), maxWindowHeight(windowHeight) {}

	sf::Vector2f Transformation::toScreenPixels(const arkanoid::Vector2D &vector) {
		return sf::Vector2f(vector.x * widthScale, maxWindowHeight - (vector.y * heightScale));
	}

}