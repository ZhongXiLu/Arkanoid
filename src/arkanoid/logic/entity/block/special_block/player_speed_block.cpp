/// \file player_speed_block.cpp

#include "player_speed_block.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	PlayerSpeedBlock::PlayerSpeedBlock() {}

	PlayerSpeedBlock::PlayerSpeedBlock(double x, double y, double speedF, pair<double, double> size) : speedFactor(speedF), Block(x, y, size) {}

	PlayerSpeedBlock::~PlayerSpeedBlock() {}

	void PlayerSpeedBlock::update() {
		Block::update();
	}

	void PlayerSpeedBlock::draw() const {
		Block::draw();
	}

	void PlayerSpeedBlock::effectPlayer(unique_ptr<Player> &player) const {
		player->speedUp(speedFactor);
	}
	
}