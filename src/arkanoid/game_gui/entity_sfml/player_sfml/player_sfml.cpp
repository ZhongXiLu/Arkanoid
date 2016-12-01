
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, double speed, const string &textureFile) :
	windowSFML(window), transformation(transform), Player(x, y, speed) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		// Center of screen
		sprite.setPosition((windowSFML.getSize().x/2)-66, windowSFML.getSize().y-100);
	}

	PlayerSFML::~PlayerSFML() {}

	void PlayerSFML::update() {

		// Note: prevents user from pressing both left and right arrow key
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			velocity.x = speed;
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			velocity.x = -speed;
		} else {
			// Player is not moving
			velocity.x = 0;
		}

		sprite.move(velocity.x, velocity.y);
		Player::setPosition(std::move(transformation->toGrid(sprite.getPosition())));
		// windowSFML.draw(sprite);
	}

	void PlayerSFML::draw() const {
		windowSFML.draw(sprite);
	}
}