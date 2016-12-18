
#include "sfml_factory.h"
#include "nlohmann/json.hpp"
#include "../game_gui/entity_sfml/player_sfml/player_sfml.h"
#include "../game_gui/entity_sfml/ball_sfml/ball_sfml.h"
#include "../game_gui/entity_sfml/wall_sfml/wall_sfml.h"
#include "../game_gui/entity_sfml/block_sfml/block_sfml.h"
#include "../game_gui/entity_sfml/block_sfml/special_block_sfml/speed_block_sfml.h"
#include "../game_gui/entity_sfml/block_sfml/special_block_sfml/invis_block_sfml.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map> 	// needed for json parse library (represents json object)

using namespace std;
using json = nlohmann::json;

SFMLFactory::SFMLFactory(sf::RenderWindow &window) : windowSFML(window) {}

// TBI: read data from file?

unique_ptr<arkanoid::Player> SFMLFactory::createPlayer() {
	unique_ptr<arkanoid::Player> player(new arkanoidSFML::PlayerSFML(400.0, 600.0, windowSFML));
	return player;
}

vector<unique_ptr<arkanoid::Wall>> SFMLFactory::createWalls() {

	vector<unique_ptr<arkanoid::Wall>> walls;

	for(double w = 0.0; w < 700.0; w += 30.0) {
		{
			unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(0.0, w, windowSFML));
			walls.push_back(std::move(wall));
		}
		{
			unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(866.0, w, windowSFML));
			walls.push_back(std::move(wall));
		}
	}
	for(double w = 0.0; w < 900.0; w += 30) {
		unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(w, 0.0, windowSFML));
		walls.push_back(std::move(wall));
	}

	return walls;
}

vector<unique_ptr<arkanoid::Block>> SFMLFactory::createBlocks(const string &file) {
	json jsonFile;
	ifstream stream(file);

	if(!stream.good()) {
		throw runtime_error("Couldn't open data/levels/level_1/blocks.json.");
	}
	
	// Parse json file
	try {
		stream >> jsonFile;
	} catch(...) {
		throw runtime_error("Couldn't parse data/levels/level_1/blocks.json.");
	}

	vector<unique_ptr<arkanoid::Block>> blocks;
	try {

		// Construct data
		vector<unordered_map<string, json>> data = jsonFile["blocks"].get<vector<unordered_map<string, json>>>();

		for(auto d: data) {
			string type = "";
			try {
				type = d["type"].get<string>();
			} catch(...) {}

			if(type == "speed") {
				unique_ptr<arkanoid::Block> block(new arkanoidSFML::SpeedBlockSFML(d["x"].get<double>(), d["y"].get<double>(), windowSFML, "data/sprites/blocks/" + d["color"].get<string>() + "_block.png"));
				blocks.push_back(std::move(block));

			} else if(type == "invis") {
				unique_ptr<arkanoid::Block> block(new arkanoidSFML::InvisBlockSFML(d["x"].get<double>(), d["y"].get<double>(), windowSFML, "data/sprites/blocks/" + d["color"].get<string>() + "_block.png"));
				blocks.push_back(std::move(block));

			} else {
				unique_ptr<arkanoid::Block> block(new arkanoidSFML::BlockSFML(d["x"].get<double>(), d["y"].get<double>(), windowSFML, "data/sprites/blocks/" + d["color"].get<string>() + "_block.png"));
				blocks.push_back(std::move(block));
			}
			
		}

	} catch(...) {
		throw runtime_error("Invalid data in data/levels/level_1/blocks.json.");
	}

	return blocks;
}

unique_ptr<arkanoid::Ball> SFMLFactory::createBall() {
	unique_ptr<arkanoid::Ball> ball(new arkanoidSFML::BallSFML(400.00, 578.0, windowSFML));
	return ball;
}