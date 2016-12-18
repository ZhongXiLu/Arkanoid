#ifndef WORLD_H
#define WORLD_H

#include "entity/entity.h"
#include "entity/wall/wall.h"
#include "entity/ball/ball.h"
#include "entity/player/player.h"
#include "entity/block/block.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoid {

	/// The World of the Arkanoid game that contains all Entity objects.
	class World : public Entity {
	private:
		unique_ptr<Ball> ball;
		unique_ptr<Player> player;
		vector<unique_ptr<Wall>> walls;
		vector<unique_ptr<Block>> blocks;

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
		* Adds a Block to the World.
		*
		* @param block		The Block that will be added to the World.
		*/
		void addBlock(unique_ptr<arkanoid::Block> block);

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

#endif /* WORLD_H */