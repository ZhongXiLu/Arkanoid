#ifndef SPEED_BLOCK_H
#define SPEED_BLOCK_H

#include "../block.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// A "special" Block: when hit with a Ball, speed up the Ball.
	class SpeedBlock : virtual public Block {

	public:

		/**
		* Default Constructor.
		*
		* Initialise the SpeedBlock at origin ([0, 0]) in the World.
		*/
		SpeedBlock();

		/**
		* Constructor.
		*
		* Initialise the SpeedBlock at a specific position in the World.
		*
		* @param x		The x position (in the grid) of the SpeedBlock.
		* @param y		The y position (in the grid) of the SpeedBlock.
		* @param size	(optional) The size (width and height respectively) of the SpeedBlock.
		*/
		SpeedBlock(double x, double y, pair<double, double> size = make_pair(1, 2));

		/**
		* Destructor.
		*/
		~SpeedBlock();
		
		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const;

		/**
		* If there was a collision, effect the Ball if necessary.
		* In this case, speed up the Ball.
		*
		* @param ball	The Ball that will be effected.
		*/
		virtual void effectBall(unique_ptr<Ball> &ball) const;
	};

}

#endif /* SPEED_BLOCK_H */