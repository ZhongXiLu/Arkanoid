#ifndef PLAYER_H
#define PLAYER_H

#include "../math/vector2D.h"

#include <iostream>

using namespace std;

class Player {
private:
	Vector2D playerPos;	///< The current position of the Player (in the 9x7 grid).

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
	* Get the current position of the Player.
	*
	* @return The current position of the Player (in a Vector2D).
	*/
	Vector2D getPos() const;

	/*
	* Moves the Player.
	*
	* @param newPos	The Vector2D over which the Player will be translated.
	*
	* @return True if move was valid and made, otherwise False.
	*/
	bool move(Vector2D newPos);
	
};

#endif /* PLAYER_H */