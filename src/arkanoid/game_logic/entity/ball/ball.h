#ifndef BALL_H
#define BALL_H

#include "../entity.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// The Ball in the Arkanoid game.
	class Ball : public Entity {
	private:
		Vector2D velocity;
		double speed;

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
		* @param x 	The x position (in the grid) of the Ball.
		* @param y 	The y position (in the grid) of the Ball.
		*/
		Ball(double x, double y);

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