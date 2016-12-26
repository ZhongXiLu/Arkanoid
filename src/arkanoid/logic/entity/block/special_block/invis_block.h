/// \file invis_block.h

#ifndef INVIS_BLOCK_H
#define INVIS_BLOCK_H

#include "../block.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// A "special" Block: when hit with a Ball, make the Ball invisible.
	class InvisBlock : virtual public Block {

	public:

		/**
		* Default Constructor.
		*
		* Initialise the InvisBlock at origin ([0, 0]) in the World.
		*/
		InvisBlock();

		/**
		* Constructor.
		*
		* Initialise the InvisBlock at a specific position in the World.
		*
		* @param x		The x position (in the grid) of the InvisBlock.
		* @param y		The y position (in the grid) of the InvisBlock.
		* @param size	(optional) The size (width and height respectively) of the InvisBlock.
		*/
		InvisBlock(double x, double y, pair<double, double> size = make_pair(1, 2));

		/**
		* Destructor.
		*/
		~InvisBlock();
		
		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const;

		/**
		* Activate this InvisBlock 'speciality': make the Ball invisible for a period of time.
		*
		* @param ball	The Ball that will be effected.
		*/
		void effectBall(unique_ptr<Ball> &ball) const;
	};

}

#endif /* INVIS_BLOCK_H */