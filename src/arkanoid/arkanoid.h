#ifndef ARKANOID_H
#define ARKANOID_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/// The actual game that can be run. Interacts with the Game Logic and the Game GUI.
class Arkanoid {
private:
	RenderWindow window;

public:

	/**
	* Default Constructor.
	*
	* Creates a game window.
	*/
	Arkanoid();

	/**
	* Run the Arkanoid game until the user closes the window.
	*
	* Cycles through the game and checks for events each cycle, depending on this event the game will update all it's data.
	*/
	void run();
};

#endif /* ARKANOID_H */