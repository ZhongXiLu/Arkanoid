/// \file player.h

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
		Vector2D origin;	///< The initial position of the Player.
		double originalSpeed;

		bool notMoving;
		int effectDuration;	///< In frames

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
		* @param newSpeed	(optional) The speed of the Player.
		* @param size		(optional) The size (width and height respectively) of the Player.
		*/
		Player(double x, double y, double newSpeed = 15.0, pair<double, double> size = make_pair(2.0, 1.0));

		/**
		* Destructor.
		*/
		~Player();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const;

		/**
		* Change the velocity of the Player by a factor.
		*
		* @param factor	The factor.
		*/
		void speedUp(double factor);

		/**
		* Reset the position of the Player to the one of the starting position.
		* (-> call this method when the Player missed the Ball).
		*/
		virtual void reset();
	};

}

#endif /* PLAYER_H */