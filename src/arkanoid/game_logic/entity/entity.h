#ifndef ENTITY_H
#define ENTITY_H

#include "math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	/// An Entity represents an "object" (like Player, Ball, Block, ...) in the game World.
	class Entity {
	protected:
		Vector2D playerPos;	///< The current position of the Entity (in the 9x7 grid).

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Entity at origin ([0, 0]) in the World.
		*/
		Entity();

		/*
		* Constructor
		*
		* Initialise the Entity at a specific position in the World.
		*
		* @param x 	The x position of the Entity.
		* @param y 	The y position of the Entity.
		*/
		Entity(int x, int y);

		/*
		* Get the current position of the Entity.
		*
		* @return The current position of the Entity (in a Vector2D).
		*/
		Vector2D getPos() const;
		
	};
	
}
#endif /* ENTITY_H */