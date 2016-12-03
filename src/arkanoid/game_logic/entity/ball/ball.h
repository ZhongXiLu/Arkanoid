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
		// bool isBouncing;		///< Check if ball is currently in bounce procedure (prevent multiple bounces at once).

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
		* @param speed	(optional) The speed of the Ball.
		* @param size	(optional) The size (width and height respectively) of the Ball.
		*/
		Ball(double x, double y, double speed = 8.0, pair<double, double> size = make_pair(1.0, 1.0));

		/**
		* Destructor.
		*/
		~Ball();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const ;

		/**
		* In case of a collision, rotate the Ball 's direction by around 90° to the right angle.
		*
		* @param other	The Entity on which the Ball is collided (needed to decide to correct angle).
		*/
		void bounce(unique_ptr<Entity> const &other);

	};

}

#endif /* BALL_H */