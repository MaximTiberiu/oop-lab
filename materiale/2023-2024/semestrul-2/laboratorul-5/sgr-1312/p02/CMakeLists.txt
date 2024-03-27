cmake_minimum_required(VERSION 3.23)
project(p02)

set(CMAKE_CXX_STANDARD 14)

add_executable(p02 main.cpp src/Meteo.cpp headers/Meteo.hpp src/Furtuna.cpp headers/Furtuna.hpp)
