cmake_minimum_required(VERSION 3.13)
project (platformer)

add_library(srcl "")
add_subdirectory(src)

add_executable(platformer main.cpp)

target_link_libraries(platformer PUBLIC srcl)


#TESTS

add_executable(tests test/vector_test.cpp)
target_link_libraries(tests PRIVATE srcl)
enable_testing()
add_test(
    NAME tests
    COMMAND $<TARGET_FILE:tests>
)