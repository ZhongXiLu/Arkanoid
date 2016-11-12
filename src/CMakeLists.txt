CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Arkanoid)

SET(CMAKE_CXX_FLAGS "-std=c++11")

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../cmake/Modules/")
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

SET(SRC 
	arkanoid/game_logic/entity/entity.cpp
	arkanoid/game_logic/entity/player/player.cpp
	arkanoid/game_logic/math/vector2D.cpp

	arkanoid/game_gui/world.cpp
	arkanoid/game_gui/math/screen.cpp
	arkanoid/game_gui/entity_sfml/player_sfml/player_sfml.cpp

	arkanoid/arkanoid.cpp

	main.cpp
)

ADD_LIBRARY(game_logic STATIC
	arkanoid/game_logic/entity/entity.cpp
	arkanoid/game_logic/entity/player/player.cpp
	arkanoid/game_logic/math/vector2D.cpp
)

ADD_LIBRARY(game_gui STATIC
	arkanoid/game_gui/world.cpp
	arkanoid/game_gui/math/screen.cpp
	arkanoid/game_gui/entity_sfml/player_sfml/player_sfml.cpp
)

ADD_EXECUTABLE(arkanoid ${SRC})
TARGET_LINK_LIBRARIES(arkanoid ${SFML_LIBRARIES})

INSTALL(TARGETS arkanoid DESTINATION ${PROJECT_SOURCE_DIR}/../bin)