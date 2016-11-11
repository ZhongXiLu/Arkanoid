#ifndef WORLD_H
#define WORLD_H

#include "player/player.h"

#include <iostream>

using namespace std;

class World {
public:
	Player player;	///< The only Player in this World.

	/**
	* Default Constructor.
	*/
	World();
	
};

#endif /* WORLD_H */