#ifndef WORLD_H
#define WORLD_H

#include "entity_sfml/player_sfml/player_sfml.h"

#include <iostream>

using namespace std;

namespace arkanoidSFML {

	/// The World of the Arkanoid game that contains all entities like the Player, Ball, Block, ....
	class World {
	public:
		PlayerSFML player;	///< The only Player in this World.

		/**
		* Default Constructor.
		*/
		World();
		
	};

}

#endif /* WORLD_H */