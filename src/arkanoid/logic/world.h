/// \file world.h

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

/// All the game logic of the Arkanoid game.
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
		* Sets the Ball of the World.
		*
		* @param newBall	The new Ball of the World.
		*/
		void setBall(unique_ptr<arkanoid::Ball> newBall);

		/**
		* Sets the Player of the World.
		*
		* @param newPlayer	The new Player of the World.
		*/
		void setPlayer(unique_ptr<arkanoid::Player> newPlayer);

		/**
		* Checks if the level ended, i.e. when there are no more Block in the World.
		*
		* @return True if level ended, otherwise false.
		*/
		bool levelEnded() const;

	};

}

#endif /* WORLD_H */