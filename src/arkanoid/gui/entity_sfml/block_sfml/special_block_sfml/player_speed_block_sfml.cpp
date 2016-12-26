/// \file player_speed_block_sfml.cpp

#include "player_speed_block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	PlayerSpeedBlockSFML::PlayerSpeedBlockSFML(double x, double y, sf::RenderWindow &window, double speedF, const string &textureFile) : PlayerSpeedBlock(x, y, speedF), BlockSFML(x, y, window, textureFile) {}

	PlayerSpeedBlockSFML::~PlayerSpeedBlockSFML() {}

	void PlayerSpeedBlockSFML::update() {}

	void PlayerSpeedBlockSFML::draw() const {
		windowSFML.draw(sprite);
	}

}