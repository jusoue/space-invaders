cmake_minimum_required(VERSION 3.21)
project(space_invaders)

set(CMAKE_CXX_STANDARD 20)

add_executable(space_invaders
    src/main.cpp
)

add_subdirectory(lib/raylib)

target_link_libraries(space_invaders
    PRIVATE
        raylib
)

target_include_directories(space_invaders
    PRIVATE
        raylib
)