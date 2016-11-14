
#include "wall_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	WallSFML::WallSFML() {
		sprite.setOrigin(50, 0);
		sprite.setPosition(0, 0);
		transformation = nullptr;
	}

	WallSFML::WallSFML(int x, int y, const string &textureFile, shared_ptr<Transformation> transform) : transformation(transform), Wall(x, y) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		// sprite.setOrigin(50, 0);
		sprite.setPosition(std::move(transformation->toScreenPixels(playerPos)));
	}

}