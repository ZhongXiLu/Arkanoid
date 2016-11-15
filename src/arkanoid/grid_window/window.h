#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

using namespace std;

namespace Game {
	struct Window {
		string name;			///< The title of the game window.
		double width;			///< The width of the game window.
		double height;			///< The height of the game window.

		Window(string n, double w, double h);
	};
}

#endif /* WINDOW_H */