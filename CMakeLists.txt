cmake_minimum_required(VERSION 3.13)
project (platformer)

add_library(srcl "")
add_subdirectory(src)

add_executable(platformer main.cpp)

target_link_libraries(platformer PUBLIC srcl)


#TESTS 

add_executable(VectorTest test/vector_test.cpp)
add_executable(PhysicTest test/physic_test.cpp)
target_link_libraries(VectorTest PRIVATE srcl)
target_link_libraries(PhysicTest PRIVATE srcl)
enable_testing()
add_test(NAME Physic COMMAND PhysicTest)
add_test(NAME Vector COMMAND VectorTest)