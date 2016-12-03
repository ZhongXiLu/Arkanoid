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
		* @param x				The x (on screen) position of the Ball.
		* @param y				The y (on screen) position of the Ball.
		* @param window			The SFML window.
		* @param transform		The Transformation object thats needed to convert coordinates to screen pixels.
		* @param speed			(optional) The speed of the Ball.
		* @param textureFile	(optional) The file that contains the texture of the BallSFML.
		*/
		BallSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, double speed = 8.0, const string &textureFile = "data/sprites/ball/ball.png");

		/**
		* Destructor.
		*/
		~BallSFML();

		/**
		* Moves the BallSFML one frame further.
		*/
		void update();

		/**
		* Draws the BallSFML in the game window.
		*/
		void draw() const;
	};

}

#endif /* BALL_SFML_H */