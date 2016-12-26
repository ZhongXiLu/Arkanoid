/// \file ball_speed_block_sfml.h

#ifndef BALL_SPEED_BLOCK_SFML_H
#define BALL_SPEED_BLOCK_SFML_H

#include "../../../../logic/entity/block/special_block/ball_speed_block.h"
#include "../block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the arkanoid::BallSpeedBlock in the game.
	class BallSpeedBlockSFML : public arkanoid::BallSpeedBlock, public BlockSFML {
	public:

		/**
		* Constructor.
		*
		* Creates a BallSpeedBlockSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this BallSpeedBlockSFML.
		*
		* @param x				The x (on screen) position of the arkanoid::Block.
		* @param y				The y (on screen) position of the arkanoid::Block.
		* @param window			The SFML window.
		* @param speedF			(optional) The factor of the speed up/down for the arkanoid::Ball.
		* @param textureFile 	(optional) The file that contains the texture of the BallSpeedBlockSFML.
		*/
		BallSpeedBlockSFML(double x, double y, sf::RenderWindow &window, double speedF = 1.5, const string &textureFile = "data/sprites/blocks/yellow_block.png");

		/**
		* Destructor.
		*/
		~BallSpeedBlockSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the BallSpeedBlockSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* BALL_SPEED_BLOCK_SFML_H */