/// \file player_sfml.cpp

#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML(double x, double y, sf::RenderWindow &window, double speed, const string &textureFile) :
	screenOrigin(x, y), windowSFML(window), transformation(Transformation::getInstance()), Player(0, 0, speed) {

		// Set texture
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load player texture image: " + textureFile);
		}
		texture.setSmooth(true);
		sprite.setTexture(texture);
		
		// Set position
		sprite.setPosition(x, y);
		setPosition(std::move(transformation->convertVector(sprite.getPosition())));

		// Set size (width and height) of PlayerSFML
		sf::FloatRect rect = sprite.getLocalBounds();
		setSize(make_pair(transformation->convertX(rect.width), transformation->convertY(rect.height)));
	}

	PlayerSFML::~PlayerSFML() {}

	void PlayerSFML::update() {

		// Check if any special effects ran out
		if(effectDuration > 0) {
			effectDuration--;
			if(effectDuration == 0) {
				speed = originalSpeed;
			}
		}

		if(!notMoving) {

			// Note: prevents user from pressing both left and right arrow key
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && sprite.getPosition().x < windowSFML.getSize().x - 33 - sprite.getLocalBounds().width) {
				velocity.x = speed;
			} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && sprite.getPosition().x > 33) {
				velocity.x = -speed;
			} else {
				// Player is not moving
				velocity.x = 0;
			}

			sprite.move(velocity.x, velocity.y);
			setPosition(std::move(transformation->convertVector(sprite.getPosition())));

		} else {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
				notMoving = false;
			}
		}
	}

	void PlayerSFML::draw() const {
		windowSFML.draw(sprite);
	}

	void PlayerSFML::reset() {
		sprite.setPosition(screenOrigin.x, screenOrigin.y);
		Player::reset();
	}
}