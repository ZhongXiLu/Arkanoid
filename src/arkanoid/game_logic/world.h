#ifndef WORLD_H
#define WORLD_H

#include "entity/entity.h"
#include "entity/ball/ball.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	/// The World of the Arkanoid game that contains all Entity objects.
	class World : public Entity {
	private:
		///< List of all Entity in the World.
		vector<unique_ptr<arkanoid::Entity>> entities;

		///< Need to keep track of the Ball for collision detection.
		unique_ptr<arkanoid::Ball> ball;

	public:
		/**
		* Default Constructor.
		*/
		World();

		/**
		* Destructor.
		*/
		~World();

		/**
		* Updates all Entity in the World.
		*/
		void update();

		/**
		* Draws all Entity in the World.
		*/
		void draw() const;

		/**
		* Adds an Entity to the World.
		*
		* @param entity		The Entity that will be added to the World.
		*/
		void addEntity(unique_ptr<arkanoid::Entity> entity);

		/**
		* Set the Ball of the World.
		*
		* @param newBall	The new Ball of the World.
		*/
		void setBall(unique_ptr<arkanoid::Ball> newBall);

	};

}

#endif /* WORLD_H */