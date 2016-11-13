#ifndef WORLD_H
#define WORLD_H

#include "entity_sfml/player_sfml/player_sfml.h"
#include "math/transformation.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The World of the Arkanoid game that contains all entities of the Game Logic, as well as all entities of the GUI side.
	class World {
	private:
		shared_ptr<Transformation> transformation;

	public:
		PlayerSFML player;	///< The only Player in this World.

		/**
		* Default Constructor.
		*/
		World();

		/**
		* Constructor.
		*
		* @param transform 	The Transformation object thats needed to convert coordinates to screen pixels.
		*/
		World(shared_ptr<Transformation> transform);
	};

}

#endif /* WORLD_H */