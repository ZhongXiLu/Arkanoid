
#include "../../arkanoid.h"		// GLOBAL VARIABLES (SCREEN::WIDTH, GRID::WIDTH, ...)
#include "screen.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	sf::Vector2f toScreenPixels(const arkanoid::Vector2D &vector) {
		return sf::Vector2f(vector.x * (SCREEN::WIDTH/GRID::WIDTH), SCREEN::HEIGHT - (vector.y * (SCREEN::HEIGHT/GRID::HEIGHT)));
	}

}