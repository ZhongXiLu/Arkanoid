CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Arkanoid)

SET(CMAKE_CXX_FLAGS "-std=c++11")


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../cmake/Modules/")
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})


ADD_LIBRARY(game_logic STATIC
	arkanoid/game_logic/entity/entity.cpp
	arkanoid/game_logic/entity/player/player.cpp
	arkanoid/game_logic/entity/ball/ball.cpp
	arkanoid/game_logic/entity/wall/wall.cpp
	arkanoid/game_logic/entity/block/block.cpp
	arkanoid/game_logic/entity/block/special_block/speed_block.cpp

	arkanoid/game_logic/math/vector2D.cpp
	arkanoid/game_logic/math/random.cpp

	arkanoid/game_logic/world.cpp
)

ADD_LIBRARY(game_gui STATIC
	arkanoid/game_gui/math/transformation.cpp
	
	arkanoid/game_gui/entity_sfml/player_sfml/player_sfml.cpp
	arkanoid/game_gui/entity_sfml/ball_sfml/ball_sfml.cpp
	arkanoid/game_gui/entity_sfml/wall_sfml/wall_sfml.cpp
	arkanoid/game_gui/entity_sfml/block_sfml/block_sfml.cpp
	arkanoid/game_gui/entity_sfml/block_sfml/special_block_sfml/speed_block_sfml.cpp
)

SET(SRC 

	arkanoid/factory/sfml_factory.cpp
	arkanoid/arkanoid.cpp

	main.cpp
)

ADD_EXECUTABLE(arkanoid ${SRC})
TARGET_LINK_LIBRARIES(arkanoid ${SFML_LIBRARIES})
TARGET_LINK_LIBRARIES(arkanoid game_logic)
TARGET_LINK_LIBRARIES(arkanoid game_gui)
TARGET_LINK_LIBRARIES(game_gui game_logic)

INSTALL(TARGETS arkanoid DESTINATION ${PROJECT_SOURCE_DIR}/../bin)