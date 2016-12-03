
#include "player_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSFML::PlayerSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, double speed, const string &textureFile) :
	windowSFML(window), transformation(transform), Player(transform->convertX(x), transform->convertY(y), speed) {

		// Set texture
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		// Set position
		sprite.setPosition(x, y);
		setPosition(std::move(transformation->convertVector(sprite.getPosition())));

		// Set size (width and height) of PlayerSFML
		sf::FloatRect rect = sprite.getLocalBounds();
		setSize(make_pair(transform->convertX(rect.width), transform->convertY(rect.height)));
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
		setPosition(std::move(transformation->convertVector(sprite.getPosition())));
	}

	void PlayerSFML::draw() const {
		windowSFML.draw(sprite);
	}
}