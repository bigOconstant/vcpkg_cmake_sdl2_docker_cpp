# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
project(test)
include(/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

find_package(SDL2 CONFIG REQUIRED)

find_package(sdl2-mixer CONFIG REQUIRED)

find_package(nlohmann_json REQUIRED)

find_package(SDL2PP REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)


add_executable(main main.cpp primitives.cpp board.cpp game.cpp player.cpp ghost.cpp)

target_include_directories(main PRIVATE ${SDL2PP_INCLUDE_DIRS} board.h game.h player.h primitives.h ghost.h)


target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3
 nlohmann_json::nlohmann_json SDL2::SDL2main SDL2::SDL2-static 
 SDL2::SDL2_mixer SDL2::SDL2_ttf SDL2::SDL2_image ${SDL2PP_LIBRARIES} SDL2::SDL2_gfx)



