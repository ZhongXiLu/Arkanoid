
#include "wall_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	WallSFML::WallSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, const string &textureFile) : windowSFML(window), transformation(transform), Wall(transform->convertX(x), transform->convertY(y)) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		// sprite.scale(3, 3);
		sprite.setPosition(x, y);
		// sprite.setPosition(x*100.0, y*100.0);
	}

	WallSFML::~WallSFML() {}

	void WallSFML::update() {
		// windowSFML.draw(sprite);
	}

	void WallSFML::draw() const {
		windowSFML.draw(sprite);
	}

}