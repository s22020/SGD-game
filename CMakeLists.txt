cmake_minimum_required(VERSION 3.25)
project (SGD-game)

set(CMAKE_CXX_STANDARD 17)


set(SDL2_INCLUDE_DIR "C:/Users/Zuza/SDL2/SDL2-2.26.5/include")
set(SDL2_LIB_DIR "C:/Users/Zuza/SDL2/SDL2-2.26.5/lib/x64")

include_directories(${SDL2_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp core/game.h core/game.cpp render/render.h render/render.cpp character/player.h character/player.cpp physics/vector2d.h physics/vector2d.cpp physics/transform.h physics/transform.cpp objects/object.h character/character.h character/character.cpp animation/animation.cpp animation/animation.h physics/rigidbody.h physics/rigidbody.cpp character/enemy.cpp character/enemy.h collision/collisionhandler.cpp collision/collisionhandler.h render/levelmap.h render/levelmap.cpp collision/collider.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib ${SDL2_LIB_DIR}/SDL2_image.lib)

