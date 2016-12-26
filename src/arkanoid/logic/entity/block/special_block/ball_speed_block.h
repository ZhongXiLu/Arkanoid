/// \file ball_speed_block.h

#ifndef BALL_SPEED_BLOCK_H
#define BALL_SPEED_BLOCK_H

#include "../block.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// A "special" Block: when hit with a Ball, speed up or slow down the Ball.
	class BallSpeedBlock : virtual public Block {
	private:
		double speedFactor;

	public:

		/**
		* Default Constructor.
		*
		* Initialise the BallSpeedBlock at origin ([0, 0]) in the World.
		*/
		BallSpeedBlock();

		/**
		* Constructor.
		*
		* Initialise the BallSpeedBlock at a specific position in the World.
		*
		* @param x			The x position (in the grid) of the BallSpeedBlock.
		* @param y			The y position (in the grid) of the BallSpeedBlock.
		* @param speedF		(optional) The factor of the speed up/down for the Ball.
		* @param size		(optional) The size (width and height respectively) of the BallSpeedBlock.
		*/
		BallSpeedBlock(double x, double y, double speedF = 1.5, pair<double, double> size = make_pair(1, 2));

		/**
		* Destructor.
		*/
		~BallSpeedBlock();
		
		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const;

		/**
		* Activate this BallSpeedBlock 'speciality': speed up or slow down the Ball, depending on the speed factor.
		*
		* @param ball	The Ball that will be effected.
		*/
		void effectBall(unique_ptr<Ball> &ball) const;
	};

}

#endif /* BALL_SPEED_BLOCK_H */