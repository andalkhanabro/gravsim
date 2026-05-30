

cmake_minimum_required(VERSION 3.10)

project(gravsim)

find_package(raylib REQUIRED)

add_executable(gravsim src/particle.cpp src/world.cpp src/main.cpp src/renderer.cpp)

target_link_libraries(gravsim raylib)