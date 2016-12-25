/// \file ball_speed_block.cpp

#include "ball_speed_block.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	BallSpeedBlock::BallSpeedBlock() {}

	BallSpeedBlock::BallSpeedBlock(double x, double y, double speedF, pair<double, double> size) : speedFactor(speedF), Block(x, y, size) {}

	BallSpeedBlock::~BallSpeedBlock() {}

	void BallSpeedBlock::update() {
		Block::update();
	}

	void BallSpeedBlock::draw() const {
		Block::draw();
	}

	void BallSpeedBlock::effectBall(unique_ptr<Ball> &ball) const {
		ball->speedUp(speedFactor);
	}
	
}