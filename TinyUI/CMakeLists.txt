cmake_minimum_required(VERSION 3.25)
project(TinyUI)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

add_library(
        TinyUI
        SHARED
        src/TinyUI.cpp
        src/Binding.cpp
        src/Painting.cpp
        src/Geometry.cpp
        src/Path.cpp)
