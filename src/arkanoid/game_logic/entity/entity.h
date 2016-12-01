#ifndef ENTITY_H
#define ENTITY_H

#include "../math/vector2D.h"

#include <iostream>

using namespace std;

namespace arkanoid {

	/// An Entity represents an "object" (like Player, Ball, Block, ...) in the game World.
	class Entity {
	protected:
		Vector2D position;		///< The current position of the Entity (in the 9x7 grid).

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Entity at origin ([0, 0]) in the World.
		*/
		Entity();

		/*
		* Constructor
		*
		* Initialise the Entity at a specific position in the World.
		*
		* @param x 	The x position of the Entity.
		* @param y 	The y position of the Entity.
		*/
		Entity(double x, double y);

		/*
		* Destructor
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

		/*
		* Get the current position of the Entity.
		*
		* @return	The current position of the Entity (in a Vector2D).
		*/
		Vector2D getPosition() const;

		/*
		* Set the current position of the Entity.
		*
		* @param x 	The nex 'x' component of the Entity.
		* @param y 	The nex 'y' component of the Entity.
		*/
		void setPosition(double x, double y);

		/*
		* Set the current position of the Entity.
		*
		* @param vector 	The vector who this Entity will be equal to.
		*/
		void setPosition(const Vector2D &vector);
		
	};
	
}
#endif /* ENTITY_H */