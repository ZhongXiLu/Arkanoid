#ifndef ENTITY_H
#define ENTITY_H

#include "../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	/// An Entity represents an "object" (like Player, Ball, Block, ...) in the game World.
	class Entity {
	protected:
		Vector2D position;			///< The current position of the Entity (in the 9x7 grid).
		pair<double, double> size;	///< The size (width and height respectively) of the Entity.

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Entity at origin ([0, 0]) in the World.
		*/
		Entity();

		/**
		* Constructor.
		*
		* Initialise the Entity at a specific position in the World.
		*
		* @param x			The x position of the Entity.
		* @param y			The y position of the Entity.
		* @param newSize	(optional) The size (width and height respectively) of the Entity.
		*/
		Entity(double x, double y, pair<double, double> newSize = make_pair(1.0, 1.0));

		/**
		* Destructor.
		*/
		virtual ~Entity() {}

		/**
		* Based on what Entity, the Entity will update itself.
		*/
		virtual void update() = 0;

		/**
		* Draw the Entity.
		*/
		virtual void draw() const = 0;

		/**
		* Get the current position of the Entity.
		*
		* @return	The current position of the Entity (in a Vector2D).
		*/
		Vector2D getPosition() const;

		/**
		* Set the current position of the Entity.
		*
		* @param x	The nex 'x' component of the Entity.
		* @param y	The nex 'y' component of the Entity.
		*/
		void setPosition(double x, double y);

		/**
		* Set the current position of the Entity.
		*
		* @param vector		The vector who this Entity will be equal to.
		*/
		void setPosition(const Vector2D &vector);

		/**
		* Set the size of the Entity.
		*
		* @param newSize	The new size of the Entity.
		*/
		void setSize(pair<double, double> newSize);

		/**
		* Get the size of the Entity.
		*
		* @return	The size of the Entity.
		*/
		pair<double, double> getSize() const;

		/**
		* Checks if this Entity is intersecting with another Entity.
		*
		* @return	True if intersecting, otherwise false.
		*/
		bool collidesWith(unique_ptr<Entity> const &other) const;

	};
	
}
#endif /* ENTITY_H */