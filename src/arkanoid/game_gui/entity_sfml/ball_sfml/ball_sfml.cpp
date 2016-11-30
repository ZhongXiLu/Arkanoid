
#include "ball_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	BallSFML::BallSFML(double x, double y, sf::RenderWindow &window, const string &textureFile, shared_ptr<Transformation> transform) :
	windowSFML(window), transformation(transform), Ball(x, y) {

		// scale = ...

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		sprite.setPosition((windowSFML.getSize().x/2), windowSFML.getSize().y);
	}

	BallSFML::~BallSFML() {}

	void BallSFML::update() {
		windowSFML.draw(sprite);
	}

}