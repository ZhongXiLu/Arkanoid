/// \file ball_speed_block_sfml.cpp

#include "ball_speed_block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	BallSpeedBlockSFML::BallSpeedBlockSFML(double x, double y, sf::RenderWindow &window, double speedF, const string &textureFile) : BallSpeedBlock(x, y, speedF), BlockSFML(x, y, window, textureFile) {}

	BallSpeedBlockSFML::~BallSpeedBlockSFML() {}

	void BallSpeedBlockSFML::update() {}

	void BallSpeedBlockSFML::draw() const {
		windowSFML.draw(sprite);
	}

}