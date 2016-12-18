
#include "speed_block.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	SpeedBlock::SpeedBlock() {}

	SpeedBlock::SpeedBlock(double x, double y, pair<double, double> size) : Block(x, y, size) {}

	SpeedBlock::~SpeedBlock() {}

	void SpeedBlock::update() {
		Block::update();
	}

	void SpeedBlock::draw() const {
		Block::draw();
	}

	void SpeedBlock::effectBall(unique_ptr<Ball> &ball) const {
		ball->speedUp(2.0);
	}
	
}