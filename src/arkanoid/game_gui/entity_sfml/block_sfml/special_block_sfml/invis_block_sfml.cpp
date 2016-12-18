
#include "invis_block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	InvisBlockSFML::InvisBlockSFML(double x, double y, sf::RenderWindow &window, const string &textureFile) : BlockSFML(x, y, window, textureFile) {}

	InvisBlockSFML::~InvisBlockSFML() {}

	void InvisBlockSFML::update() {}

	void InvisBlockSFML::draw() const {
		windowSFML.draw(sprite);
	}

}