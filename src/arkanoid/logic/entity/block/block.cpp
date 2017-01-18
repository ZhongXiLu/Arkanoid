/// \file block.cpp

#include "block.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Block::Block() {}

	Block::Block(double x, double y, pair<double, double> size) : Wall(x, y, size) {}

	Block::~Block() {}

	void Block::update() {}

	void Block::draw() const {}
	
}