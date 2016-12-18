/// \file invis_block.cpp

#include "invis_block.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	InvisBlock::InvisBlock() {}

	InvisBlock::InvisBlock(double x, double y, pair<double, double> size) : Block(x, y, size) {}

	InvisBlock::~InvisBlock() {}

	void InvisBlock::update() {
		Block::update();
	}

	void InvisBlock::draw() const {
		Block::draw();
	}

	void InvisBlock::effectBall(unique_ptr<Ball> &ball) const {
		ball->setInvisible(true);
	}
	
}