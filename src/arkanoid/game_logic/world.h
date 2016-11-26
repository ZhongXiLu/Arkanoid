#ifndef WORLD_H
#define WORLD_H

#include "entity/entity.h"
#include "grid/grid.h"
#include "../window/window.h"
#include "../game_gui/math/transformation.h"

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

		vector<arkanoid::Entity*> entities;		///< List of all Entity in the World.

	public:
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
		* Add an Entity to the World.
		*
		* @param entity		The Entity that will be added.
		*/
		void addEntity(arkanoid::Entity* entity);

	};

}

#endif /* WORLD_H */