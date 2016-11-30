#ifndef BALL_SFML_H
#define BALL_SFML_H

#include "../../../game_logic/entity/ball/ball.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Ball in the game.
	class BallSFML : public arkanoid::Ball {
	private:
		sf::RenderWindow &windowSFML;

		sf::Sprite sprite;	///< The sprite of the BallSFML.
		sf::Texture texture;

		shared_ptr<Transformation> transformation;

	public:
		/**
		* Constructor.
		*
		* Creates a BallSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this BallSFML.
		*
		* @param x				The x (in the grid) position of the Ball.
		* @param y				The y (in the grid) position of the Ball.
		* @param window			The SFML window.
		* @param textureFile	The file that contains the texture of the BallSFML.
		* @param transform		The Transformation object thats needed to convert coordinates to screen pixels.
		*/
		BallSFML(double x, double y, sf::RenderWindow &window, const string &textureFile, shared_ptr<Transformation> transform);

		/**
		* Destructor.
		*/
		~BallSFML();

		/**
		* Moves the BallSFML one frame further.
		*/
		void update();

	};

}

#endif /* BALL_SFML_H */