#ifndef WORLD_H
#define WORLD_H

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

	/// The World of the Arkanoid game that contains all Entity objects.
	class World : public Entity {
	private:
		shared_ptr<Ball> ball;
		shared_ptr<Player> player;
		vector<shared_ptr<Wall>> walls;
		vector<shared_ptr<Entity>> entities;

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
		void addEntity(shared_ptr<arkanoid::Entity> entity);

		/**
		* Adds a Wall to the World.
		*
		* @param wall		The Wall that will be added to the World.
		*/
		void addWall(shared_ptr<arkanoid::Wall> wall);

		/**
		* Set the Ball of the World.
		*
		* @param newBall	The new Ball of the World.
		*/
		void setBall(shared_ptr<arkanoid::Ball> newBall);

		/**
		* Set the Player of the World.
		*
		* @param newPlayer	The new Player of the World.
		*/
		void setPlayer(shared_ptr<arkanoid::Player> newPlayer);

	};

}

#endif /* WORLD_H */