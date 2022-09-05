cmake_minimum_required(VERSION 3.5)

project(patches LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(patches main.cpp)

install(TARGETS patches
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
