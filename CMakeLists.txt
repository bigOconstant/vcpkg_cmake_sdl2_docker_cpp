# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
project(test)
include(/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(unofficial-sqlite3 CONFIG REQUIRED)


find_package(nlohmann_json REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3 nlohmann_json::nlohmann_json)