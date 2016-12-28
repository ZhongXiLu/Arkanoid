/// \file ball_sfml.cpp

#include "ball_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	BallSFML::BallSFML(double x, double y, sf::RenderWindow &window, double speed, const string &textureFile) :
	screenOrigin(x, y), windowSFML(window), transformation(Transformation::getInstance()), Ball(0, 0, speed) {

		// Set texture
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load ball texture image: " + textureFile);
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

	BallSFML::~BallSFML() {}

	void BallSFML::update() {
		if(invisDuration > 0) {
			invisDuration--;
		}

		if(!notMoving) {
			// Move the ball
			sprite.move(velocity.x, velocity.y);
			setPosition(std::move(transformation->convertVector(sprite.getPosition())));
		} else {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
				notMoving = false;
			}
		}
	}

	void BallSFML::draw() const {
		if(invisDuration == 0.0) {
			windowSFML.draw(sprite);
		}
	}

	void BallSFML::reset() {
		sprite.setPosition(screenOrigin.x, screenOrigin.y);
		Ball::reset();
	}
}