#ifndef SCREEN_H
#define SCREEN_H

#include "../../game_logic/math/vector2D.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	sf::Vector2f toScreenPixels(const arkanoid::Vector2D &vector);

}

#endif /* SCREEN_H */