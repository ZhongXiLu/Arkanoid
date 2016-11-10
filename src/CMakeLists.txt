CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Arkanoid)

SET(CMAKE_CXX_FLAGS "-std=c++11")

SET(
	SRC 
	
	main.cpp

	arkanoid/arkanoid.cpp
	arkanoid/game_logic/player/player.cpp
)

ADD_EXECUTABLE(arkanoid ${SRC})
INSTALL(TARGETS arkanoid DESTINATION ${PROJECT_SOURCE_DIR}/../bin)