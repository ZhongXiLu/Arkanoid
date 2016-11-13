
#include "world.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	World::World(shared_ptr<Transformation> transform) : transformation(transform), player(4, 1, "sprites/player/player.png", transformation) {}

}