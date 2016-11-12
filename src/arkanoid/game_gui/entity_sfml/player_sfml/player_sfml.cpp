
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML() {
		sprite.setPosition(sf::Vector2f(100, 100));
	}

	PlayerSFML::PlayerSFML(int x, int y, const string &textureFile) : Player(x, y) {
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}

		sprite.setTexture(texture);

		// Translate to screen pixels
		// sf::Vector2f position = toScreenPixels(x, y);
		// sprite.setPosition(position);
	}

}