
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML() {
		sprite.setOrigin(50, 0);
		sprite.setPosition(0, 0);
		transformation = nullptr;
	}

	PlayerSFML::PlayerSFML(int x, int y, const string &textureFile, shared_ptr<Transformation> transform) : transformation(transform), Player(x, y) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		// sprite.setOrigin(50, 0);
		sprite.setPosition(std::move(transformation->toScreenPixels(playerPos)));
	}

	bool PlayerSFML::moveLeft() {
		Player::moveLeft();
		sprite.setPosition(std::move(transformation->toScreenPixels(playerPos)));
		return true;
	}

	bool PlayerSFML::moveRight() {
		Player::moveRight();
		sprite.setPosition(std::move(transformation->toScreenPixels(playerPos)));
		return true;
	}

}