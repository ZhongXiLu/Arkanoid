
#include "ball_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	BallSFML::BallSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, double speed, const string &textureFile) :
	windowSFML(window), transformation(transform), Ball(transform->convertX(x), transform->convertY(y), speed) {

		// Set texture
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);

		// Set position
		sprite.setPosition(x, y);

		// Set size (width and height) of PlayerSFML
		sf::FloatRect rect = sprite.getLocalBounds();
		setSize(make_pair(transform->convertX(rect.width), transform->convertX(rect.height)));
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