#ifndef BLOCK_SFML_H
#define BLOCK_SFML_H

#include "../../../game_logic/entity/block/block.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Block in the game.
	class BlockSFML : public arkanoid::Block {
	private:
		sf::RenderWindow &windowSFML;

		sf::Sprite sprite; ///< The sprite of the BlockSFML.
		sf::Texture texture;
		
		shared_ptr<Transformation> transformation;

	public:

		/**
		* Constructor.
		*
		* Creates a BlockSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this BlockSFML.
		*
		* @param x				The x (on screen) position of the Block.
		* @param y				The y (on screen) position of the Block.
		* @param transform 		The Transformation object thats needed to convert coordinates to screen pixels.
		* @param textureFile 	(optional) The file that contains the texture of the BlockSFML.
		*/
		BlockSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, const string &textureFile = "data/sprites/block/block.png");

		/**
		* Destructor.
		*/
		~BlockSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the BlockSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* BLOCK_SFML_H */