/// \file sfml_factory.cpp

#include "sfml_factory.h"
#include "nlohmann/json.hpp"
#include "../gui/entity_sfml/player_sfml/player_sfml.h"
#include "../gui/entity_sfml/ball_sfml/ball_sfml.h"
#include "../gui/entity_sfml/wall_sfml/wall_sfml.h"
#include "../gui/entity_sfml/block_sfml/block_sfml.h"
#include "../gui/entity_sfml/block_sfml/special_block_sfml/ball_speed_block_sfml.h"
#include "../gui/entity_sfml/block_sfml/special_block_sfml/player_speed_block_sfml.h"
#include "../gui/entity_sfml/block_sfml/special_block_sfml/invis_block_sfml.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map> 	// needed for json parse library (represents json object)

using namespace std;
using json = nlohmann::json;

SFMLFactory::SFMLFactory(sf::RenderWindow &window) : windowSFML(window) {}

unique_ptr<arkanoid::Player> SFMLFactory::createPlayer() {
	unique_ptr<arkanoid::Player> player(new arkanoidSFML::PlayerSFML(400.0, 600.0, windowSFML));
	return player;
}

vector<unique_ptr<arkanoid::Wall>> SFMLFactory::createWalls() {

	vector<unique_ptr<arkanoid::Wall>> walls;

	// Create walls on the left and right side of the screen
	for(double y = 0.0; y < 700.0; y += 32.0) {
		{
			unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(0.0, y, windowSFML));
			walls.push_back(std::move(wall));
		}
		{
			unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(864.0, y, windowSFML));
			walls.push_back(std::move(wall));
		}
	}
	// Create walls on the top side of the screen
	for(double x = 0.0; x < 900.0; x += 32) {
		unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(x, 0.0, windowSFML));
		walls.push_back(std::move(wall));
	}

	return walls;
}

vector<unique_ptr<arkanoid::Block>> SFMLFactory::createBlocks(const string &file) {
	json jsonFile;
	ifstream stream(file);

	if(!stream.good()) {
		throw runtime_error("Couldn't open " + file);
	}
	
	// Parse json file
	try {
		stream >> jsonFile;
	} catch(...) {
		throw runtime_error("Couldn't parse " + file);
	}

	vector<unique_ptr<arkanoid::Block>> blocks;
	try {

		// Construct data
		vector<vector<string>> data = jsonFile["blocks"].get<vector<vector<string>>>();

		constexpr double offset = 32.0;
		constexpr double blockSizeW = 64.0;
		constexpr double blockSizeH = 32.0;
		for(double r = 0; r < data.size(); r++) {	// row
			for(double c = 0; c < data[r].size(); c++) {	// column

				// Check what type the current Block is
				if(data[r][c] == "Y" || data[r][c] == "P") {
					// BallSpeedBlock

					double speedFactor = 0.0;
					string color;
					if(data[r][c] == "Y") {
						speedFactor = 1.5;
						color = "yellow";
					} else {
						speedFactor = 0.5;
						color = "purple";
					}

					unique_ptr<arkanoid::Block> block(new arkanoidSFML::BallSpeedBlockSFML(offset + blockSizeW*c, offset + blockSizeH*r, windowSFML, speedFactor, "data/sprites/blocks/" + color + "_block.png"));
					blocks.push_back(std::move(block));

				} else if(data[r][c] == "R") {
					// InvisBlock
					unique_ptr<arkanoid::Block> block(new arkanoidSFML::InvisBlockSFML(offset + blockSizeW*c, offset + blockSizeH*r, windowSFML, "data/sprites/blocks/red_block.png"));
					blocks.push_back(std::move(block));

				} else if(data[r][c] == "G") {
					// PlayerSpeedBlock
					unique_ptr<arkanoid::Block> block(new arkanoidSFML::PlayerSpeedBlockSFML(offset + blockSizeW*c, offset + blockSizeH*r, windowSFML, 2.0, "data/sprites/blocks/green_block.png"));
					blocks.push_back(std::move(block));

				} else if(data[r][c] == "B") {
					// Normal Block
					unique_ptr<arkanoid::Block> block(new arkanoidSFML::BlockSFML(offset + blockSizeW*c, offset + blockSizeH*r, windowSFML, "data/sprites/blocks/blue_block.png"));
					blocks.push_back(std::move(block));
				}

			}
		}

	} catch(...) {
		throw runtime_error("Invalid data in " + file);
	}

	return blocks;
}

unique_ptr<arkanoid::Ball> SFMLFactory::createBall() {
	unique_ptr<arkanoid::Ball> ball(new arkanoidSFML::BallSFML(400.00, 578.0, windowSFML));
	return ball;
}