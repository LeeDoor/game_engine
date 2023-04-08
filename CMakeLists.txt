cmake_minimum_required(VERSION 3.2)

project (platformer)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(platformer main.cpp)
target_link_libraries(platformer ${SDL2_LIBRARIES})