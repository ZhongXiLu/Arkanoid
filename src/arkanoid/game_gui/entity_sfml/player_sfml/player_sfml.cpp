
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML() {
		sprite.setPosition(0, 0);
		transformation = nullptr;
	}

	PlayerSFML::PlayerSFML(double x, double y, const string &textureFile, shared_ptr<Transformation> transform) : transformation(transform), Player(x, y) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		sprite.setPosition(400, 600);		// CHANGE THIS LATER?
	}

	bool PlayerSFML::moveLeft() {
		sprite.move(-50.0, 0.0);
		Player::setPosition(std::move(transformation->toGrid(sprite.getPosition())));
		return true;
	}

	bool PlayerSFML::moveRight() {
		sprite.move(50.0, 0.0);
		Player::setPosition(std::move(transformation->toGrid(sprite.getPosition())));
		return true;
	}

}