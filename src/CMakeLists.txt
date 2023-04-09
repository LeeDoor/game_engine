cmake_minimum_required(VERSION 3.13)

target_sources(srcl PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/window.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/hero.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/hero.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/drawable.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/window.hpp)

target_include_directories(srcl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(srcl ${SDL2_LIBRARIES})
