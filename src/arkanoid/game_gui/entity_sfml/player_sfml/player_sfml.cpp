
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML(double x, double y, sf::RenderWindow &window, const string &textureFile, shared_ptr<Transformation> transform) :
	windowSFML(window), transformation(transform), Player(x, y) {

		// scale = ...

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		sprite.setPosition((windowSFML.getSize().x/2)-66, windowSFML.getSize().y-100);
	}

	PlayerSFML::~PlayerSFML() {}

	void PlayerSFML::update() {
		windowSFML.draw(sprite);
	}

	bool PlayerSFML::move(double x, double y) {
		sprite.move(x, y);
		Player::setPosition(std::move(transformation->toGrid(sprite.getPosition())));
		return true;
	}

}