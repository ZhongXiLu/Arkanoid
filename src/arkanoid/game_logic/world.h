#ifndef WORLD_H
#define WORLD_H

#include "player/player.h"

#include <iostream>

using namespace std;

/// The World of the Arkanoid game that contains all entities like the Player, Ball, Block, ....
class World {
public:
	Player player;	///< The only Player in this World.

	/**
	* Default Constructor.
	*/
	World();
	
};

#endif /* WORLD_H */