
#include "wall_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	WallSFML::WallSFML(double x, double y, sf::RenderWindow &window, const string &textureFile) : windowSFML(window), transformation(Transformation::getInstance()) {

		// Set texture
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load wall texture image: " + textureFile);
		}
		texture.setSmooth(true);
		sprite.setTexture(texture);
		
		// Set position
		sprite.setPosition(x, y);
		setPosition(std::move(transformation->convertVector(sprite.getPosition())));

		// Set size (width and height) of WallSFML
		sf::FloatRect rect = sprite.getLocalBounds();
		setSize(make_pair(transformation->convertX(rect.width), transformation->convertY(rect.height)));
	}

	WallSFML::~WallSFML() {}

	void WallSFML::update() {
		// ...
	}

	void WallSFML::draw() const {
		windowSFML.draw(sprite);
	}

}