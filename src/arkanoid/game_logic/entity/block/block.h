#ifndef BLOCK_H
#define BLOCK_H

#include "../wall/wall.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// The Block in the Arkanoid game, can be hit and destroyed by the Player.
	class Block : public Wall {

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Block at origin ([0, 0]) in the World.
		*/
		Block();

		/**
		* Constructor.
		*
		* Initialise the Block at a specific position in the World.
		*
		* @param x		The x position (in the grid) of the Block.
		* @param y		The y position (in the grid) of the Block.
		* @param size	(optional) The size (width and height respectively) of the Block.
		*/
		Block(double x, double y, pair<double, double> size = make_pair(1, 2));

		/**
		* Destructor.
		*/
		~Block();
		
		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const;
	};

}

#endif /* BLOCK_H */