cmake_minimum_required(VERSION 3.13)
project (platformer)
set (CMAKE_CXX_STANDARD 20)

add_library(srcl "")
add_subdirectory(src)

add_executable(platformer main.cpp)

target_link_libraries(platformer PUBLIC srcl)


#TESTS 
set(testing true)
if(testing)
    add_executable(VectorTest test/vector_test.cpp)
    add_executable(CollisionTest test/collision_test.cpp)
    target_link_libraries(VectorTest PRIVATE srcl)
    target_link_libraries(CollisionTest PRIVATE srcl)
    enable_testing()
    add_test(NAME Vector COMMAND VectorTest)
    add_test(NAME Collision COMMAND CollisionTest)
endif()