
#include "speed_block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	SpeedBlockSFML::SpeedBlockSFML(double x, double y, sf::RenderWindow &window, const string &textureFile) : BlockSFML(x, y, window, textureFile) {}

	SpeedBlockSFML::~SpeedBlockSFML() {}

	void SpeedBlockSFML::update() {}

	void SpeedBlockSFML::draw() const {
		windowSFML.draw(sprite);
	}

}