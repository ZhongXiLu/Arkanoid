#ifndef WALL_SFML_H
#define WALL_SFML_H

#include "../../../game_logic/entity/wall/wall.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Wall in the game.
	class WallSFML : public arkanoid::Wall {
	private:
		sf::RenderWindow &windowSFML;

		sf::Sprite sprite; ///< The sprite of the WallSFML.
		sf::Texture texture;
		
		shared_ptr<Transformation> transformation;

	public:

		/**
		* Constructor.
		*
		* Creates a WallSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this WallSFML.
		*
		* @param x				The x (on screen) position of the Wall.
		* @param y				The y (on screen) position of the Wall.
		* @param transform 		The Transformation object thats needed to convert coordinates to screen pixels.
		* @param textureFile 	(optional) The file that contains the texture of the WallSFML.
		*/
		WallSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, const string &textureFile = "sprites/wall/wall.png");

		/**
		* Destructor.
		*/
		~WallSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the WallSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* WALL_SFML_H */