#ifndef BALL_H
#define BALL_H

#include "../entity.h"
#include "../player/player.h"
#include "../../math/vector2D.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;


namespace arkanoid {

	/// The Ball in the Arkanoid game.
	class Ball : public Entity {
	protected:
		Vector2D velocity;
		Vector2D origin;

		bool notMoving;

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
		* Checks for all Entity if there's a collision, if there is, then "bounce" off the Entity, i.e. rotate 90° in the right direction.
		*
		* @param entities	List of all the Entity of the World (Ball not included).
		*
		* @return The indeces in the list of the Entity that the Ball collided with.
		*/
		template<typename T>
		vector<int> bounceIfPossible(vector<unique_ptr<T>> const &entities);

		/**
		* Checks if there's a collision with the Player, if there is, make the correct bounce (angle) depending on the point of collision.
		*
		* @param player		The Player of the World.
		*/
		void bounceIfPossible(unique_ptr<Player> const &player);

		/**
		* Reset the direction of the Ball and set it at a specific position.
		* (-> call this method when the Player missed the Ball).
		*/
		virtual void reset();

	};

}

#endif /* BALL_H */