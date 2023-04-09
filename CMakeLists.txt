cmake_minimum_required(VERSION 3.2)

project (platformer)

add_executable(platformer src/main.cpp src/window.cpp src/headers/window.hpp)
target_include_directories(platformer PRIVATE ${CMAKE_SOURCE_DIR}/src/headers)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(platformer ${SDL2_LIBRARIES})
