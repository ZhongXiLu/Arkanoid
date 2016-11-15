#ifndef WORLD_H
#define WORLD_H

#include "entity_sfml/player_sfml/player_sfml.h"
#include "entity_sfml/wall_sfml/wall_sfml.h"
#include "math/transformation.h"
#include "../grid_window/grid.h"
#include "../grid_window/window.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The World of the Arkanoid game that contains all Entity objects.
	class World {
	private:
		shared_ptr<Game::Window> window;
		shared_ptr<Game::Grid> grid;

		shared_ptr<Transformation> transformation;	///< Transformation object for translations between coordinates and pixels.

	public:
		PlayerSFML player;	///< The only Player in this World.
		vector<unique_ptr<WallSFML> > walls;		///< The Wall on the sides (left/top/right).

		/**
		* Default Constructor.
		*/
		World();

		/**
		* Constructor.
		*
		* @param transform 	The Transformation object thats needed to convert coordinates to screen pixels.
		*/
		World(shared_ptr<Transformation> transform, shared_ptr<Game::Window> window, shared_ptr<Game::Grid> grid);

		/**
		* Draws all the Entity objects in this World on the window.
		*
		* @param window 	The window where all the sprites will be drawn on.
		*/
		void drawAll(sf::RenderWindow &window);
	};

}

#endif /* WORLD_H */