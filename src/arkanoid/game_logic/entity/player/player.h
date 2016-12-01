#ifndef PLAYER_H
#define PLAYER_H

#include "../entity.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// The Player in the Arkanoid game that represents a "rectangle".
	class Player : public Entity {
	protected:
		Vector2D velocity;
		double speed;

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Player at origin ([0, 0]) in the World.
		*/
		Player();

		/**
		* Constructor.
		*
		* Initialise the Player at a specific position in the World.
		*
		* @param x			The x position (in the grid) of the Player.
		* @param y			The y position (in the grid) of the Player.
		* @param newSpeed	The speed of the Player.
		*/
		Player(double x, double y, double newSpeed);

		/**
		* Destructor.
		*/
		~Player();

		/**
		* Do nothing...
		*/
		void update();

	};

}

#endif /* PLAYER_H */