
#include "wall.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	Wall::Wall() : Entity(0, 0) {}

	Wall::Wall(int x, int y) : Entity(x, y) {}

}