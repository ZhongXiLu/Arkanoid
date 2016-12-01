#ifndef BALL_H
#define BALL_H

#include "../entity.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// The Ball in the Arkanoid game.
	class Ball : public Entity {
	protected:
		Vector2D velocity;

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Ball at origin ([0, 0]) in the World.
		*/
		Ball();

		/**
		* Constructor.
		*
		* Initialise the Ball at a specific position in the World.
		*
		* @param x		The x position (in the grid) of the Ball.
		* @param y		The y position (in the grid) of the Ball.
		* @param speed	The speed of the Ball.
		*/
		Ball(double x, double y, double speed);

		/**
		* Destructor.
		*/
		~Ball();

		/**
		* Moves the Ball one frame further.
		*/
		void update();

		/**
		* Set the spee
		*/

	};

}

#endif /* BALL_H */