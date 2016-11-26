
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	// PlayerSFML::PlayerSFML() {
	// 	sprite.setPosition(0, 0);
	// 	window = nullptr;
	// 	transformation = nullptr;
	// }

	PlayerSFML::PlayerSFML(double x, double y, sf::RenderWindow &window, const string &textureFile, shared_ptr<Transformation> transform) :
	windowSFML(window), transformation(transform), Player(x, y) {

		// scale = ...

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		sprite.setPosition((windowSFML.getSize().x/2)-50, windowSFML.getSize().y-100);
	}

	PlayerSFML::~PlayerSFML() {}

	void PlayerSFML::update() {
		// reference of SFML window as member

		// sf::Event event;
		// pollEvent(event);

		// if(event.type == sf::Event::KeyPressed) {

		// 	if(event.key.code == sf::Keyboard::Left) {
		// 		moveLeft();
		// 	} else if(event.key.code == sf::Keyboard::Right) {
		// 		moveRight();
		// 	}
		// }
		windowSFML.draw(sprite);
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