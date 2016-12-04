#ifndef WORLD_H
#define WORLD_H

#include "entity/entity.h"
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
		unique_ptr<arkanoid::Ball> ball;
		unique_ptr<arkanoid::Player> player;
		vector<unique_ptr<arkanoid::Entity>> entities;

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

		/**
		* Set the Player of the World.
		*
		* @param newPlayer	The new Player of the World.
		*/
		void setPlayer(unique_ptr<arkanoid::Player> newPlayer);

	};

}

#endif /* WORLD_H */