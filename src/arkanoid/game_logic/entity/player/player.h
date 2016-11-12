#ifndef PLAYER_H
#define PLAYER_H

#include "../entity.h"
#include "../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// The Player in the Arkanoid game that represents a "rectangle".
	class Player : public Entity {
	private:
		/*
		* Moves the Player.
		*
		* @param newPos	The Vector2D over which the Player will be translated.
		*
		* @return True if move was valid and made, otherwise False.
		*/
		bool move(Vector2D &newPos);

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Player at origin ([0, 0]) in the World.
		*/
		Player();

		/*
		* Constructor
		*
		* Initialise the Player at a specific position in the World.
		*
		* @param x 	The x position of the Player.
		* @param y 	The y position of the Player.
		*/
		Player(int x, int y);

		/*
		* Moves the Player one "block" to the left.
		*
		* @return True if move was valid and made, otherwise False.
		*/
		bool moveLeft();

		/*
		* Moves the Player one "block" to the right.
		*
		* @return True if move was valid and made, otherwise False.
		*/
		bool moveRight();
		
	};

}

#endif /* PLAYER_H */