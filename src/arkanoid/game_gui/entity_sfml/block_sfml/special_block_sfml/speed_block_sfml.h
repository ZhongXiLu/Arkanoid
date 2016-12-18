/// \file speed_block_sfml.h

#ifndef SPEED_BLOCK_SFML_H
#define SPEED_BLOCK_SFML_H

#include "../../../../game_logic/entity/block/special_block/speed_block.h"
#include "../block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the arkanoid::SpeedBlock in the game.
	class SpeedBlockSFML : public arkanoid::SpeedBlock, public BlockSFML {
	public:

		/**
		* Constructor.
		*
		* Creates a SpeedBlockSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this SpeedBlockSFML.
		*
		* @param x				The x (on screen) position of the arkanoid::Block.
		* @param y				The y (on screen) position of the arkanoid::Block.
		* @param textureFile 	(optional) The file that contains the texture of the SpeedBlockSFML.
		*/
		SpeedBlockSFML(double x, double y, sf::RenderWindow &window, const string &textureFile = "data/sprites/blocks/yellow_block.png");

		/**
		* Destructor.
		*/
		~SpeedBlockSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the SpeedBlockSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* SPEED_BLOCK_SFML_H */