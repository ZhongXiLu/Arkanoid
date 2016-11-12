
#include "player_sfml.h"
#include "../../math/screen.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML() {		
		sprite.setOrigin(50, 0);
		sprite.setPosition(0, 0);
	}

	PlayerSFML::PlayerSFML(int x, int y, const string &textureFile) : Player(x, y) {
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		sprite.setOrigin(50, 0);
		sprite.setPosition(std::move(toScreenPixels(playerPos)));
	}

}