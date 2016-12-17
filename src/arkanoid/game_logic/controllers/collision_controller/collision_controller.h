#ifndef COLLISION_CONTROLLER_H
#define COLLISION_CONTROLLER_H

#include "entity/entity.h"
#include "entity/wall/wall.h"
#include "entity/ball/ball.h"
#include "entity/player/player.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	/// Controller: controls all the collision in the game.
	class CollisionController {
	private:
		unique_ptr<Ball> ball;
		unique_ptr<Player> player;
		vector<unique_ptr<Wall>> walls;
		vector<unique_ptr<Entity>> entities;

	public:
		/**
		* Default Constructor.
		*/
		CollisionController();

		/**
		* Destructor.
		*/
		~CollisionController();

		/**
		* Checks for all collidable Entity in the World if it has a collision, if it has, then make the correct action. Otherwise, do nothing.
		*/
		void update();

		/**
		* Adds an Entity to the World.
		*
		* @param entity		The Entity that will be added to the World.
		*/
		void addEntity(unique_ptr<arkanoid::Entity> entity);

		/**
		* Adds a Wall to the World.
		*
		* @param wall		The Wall that will be added to the World.
		*/
		void addWall(unique_ptr<arkanoid::Wall> wall);

		/**
		* Set the Ball of the World.
		*
		* @param newBall	The new Ball of the World.
		*/
		void setBall(unique_ptr<arkanoid::Ball> newBall);

		/**
		* Set the Player of the World.
		*
		* @param newPlayer	The new Player of the World.
		*/
		void setPlayer(unique_ptr<arkanoid::Player> newPlayer);

	};

}

#endif /* COLLISION_CONTROLLER_H */