/// \file random.h

#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>

using namespace std;


namespace arkanoid {

	/// Singleton: generates "random" numbers.
	class Random {
	private:
		static Random* singleton;

		/**
		* Default Constructor.
		*/
		Random();

		// Not implemented (--> cant copy)
		Random(Random const &other);
		Random& operator=(Random const &other);

	public:

		/**
		* Get an instance of the Random object.
		*
		* @return An instance of the Random object.
		*/
		static Random* getInstance();

		/**
		* Generates a "random" double between a given range.
		*
		* @param from	The lowest value of the range.
		* @param to		The highest value of the range.
		*
		* @return		The "random" double.
		*/
		double randomDouble(int from, int to);
	};

}

#endif /* RANDOM_H */