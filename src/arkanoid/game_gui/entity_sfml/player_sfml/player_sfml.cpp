
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML() {
		sprite.setColor(sf::Color(0, 255, 0));
	}

	PlayerSFML::PlayerSFML(int x, int y) : Player(x, y) {
		// Translate to screen pixels
		// sf::Vector2f position = toScreenPixels(x, y);
		// sprite.setPosition(position);
	}

}