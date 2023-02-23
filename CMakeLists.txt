cmake_minimum_required(VERSION 3.19)


project(game)

set(CMAKE_CXX_STANDARD 20)

add_executable(game src/main.cpp)
target_link_libraries(game
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)
target_compile_options(game PRIVATE -Wall)
