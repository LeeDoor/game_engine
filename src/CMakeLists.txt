cmake_minimum_required(VERSION 3.13)

target_sources(srcl PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/window.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/hero.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vector2f.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game_object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/physic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drawable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/hero.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/physic.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/game_object.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/vector2f.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/drawable.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/window.hpp)

target_include_directories(srcl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})

target_link_libraries(srcl PUBLIC SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image)
#target_link_libraries(srcl ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})
