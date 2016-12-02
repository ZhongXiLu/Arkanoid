
#include "ball_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	BallSFML::BallSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, double speed, const string &textureFile) :
	windowSFML(window), transformation(transform), Ball(transform->convertX(x), transform->convertY(y), speed) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		// sprite.scale(1.5, 1.5);

		// On top of the Player
		// TBI: remove magic numbers?
		sprite.setPosition(x, y);
		// sprite.setPosition((windowSFML.getSize().x/2)-50, windowSFML.getSize().y-120);
	}

	BallSFML::~BallSFML() {}

	void BallSFML::update() {
		// Move the ball
		sprite.move(velocity.x, velocity.y);

		// windowSFML.draw(sprite);
	}

	void BallSFML::draw() const {
		windowSFML.draw(sprite);
	}
}