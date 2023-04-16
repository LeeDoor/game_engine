cmake_minimum_required(VERSION 3.13)

target_sources(srcl PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/application.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/render_window.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/game_object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/physic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sprite_render.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/go_builder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/go_director.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/go_builder.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/go_director.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/component.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/components.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/physic.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/game_object.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/vector2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/sprite_render.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/direction.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/render_window.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/application.hpp)

target_include_directories(srcl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})

target_link_libraries(srcl PUBLIC SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image)
#target_link_libraries(srcl ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})
