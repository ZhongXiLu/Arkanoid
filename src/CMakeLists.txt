CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Arkanoid)

SET(CMAKE_CXX_FLAGS "-std=c++11")


SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../cmake/Modules/")
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})


ADD_LIBRARY(logic STATIC
	arkanoid/logic/entity/entity.cpp
	arkanoid/logic/entity/player/player.cpp
	arkanoid/logic/entity/ball/ball.cpp
	arkanoid/logic/entity/wall/wall.cpp
	arkanoid/logic/entity/block/block.cpp
	arkanoid/logic/entity/block/special_block/ball_speed_block.cpp
	arkanoid/logic/entity/block/special_block/player_speed_block.cpp
	arkanoid/logic/entity/block/special_block/invis_block.cpp

	arkanoid/logic/math/vector2D.cpp
	arkanoid/logic/math/random.cpp

	arkanoid/logic/world.cpp
)

ADD_LIBRARY(gui STATIC
	arkanoid/gui/math/transformation.cpp
	
	arkanoid/gui/entity_sfml/player_sfml/player_sfml.cpp
	arkanoid/gui/entity_sfml/ball_sfml/ball_sfml.cpp
	arkanoid/gui/entity_sfml/wall_sfml/wall_sfml.cpp
	arkanoid/gui/entity_sfml/block_sfml/block_sfml.cpp
	arkanoid/gui/entity_sfml/block_sfml/special_block_sfml/ball_speed_block_sfml.cpp
	arkanoid/gui/entity_sfml/block_sfml/special_block_sfml/player_speed_block_sfml.cpp
	arkanoid/gui/entity_sfml/block_sfml/special_block_sfml/invis_block_sfml.cpp
)

SET(SRC 

	arkanoid/factory/sfml_factory.cpp
	arkanoid/arkanoid.cpp

	main.cpp
)

ADD_EXECUTABLE(arkanoid ${SRC})
TARGET_LINK_LIBRARIES(arkanoid ${SFML_LIBRARIES})
TARGET_LINK_LIBRARIES(arkanoid logic)
TARGET_LINK_LIBRARIES(arkanoid gui)
TARGET_LINK_LIBRARIES(gui logic)

INSTALL(TARGETS arkanoid DESTINATION ${PROJECT_SOURCE_DIR}/../bin)