cmake_minimum_required(VERSION 3.25)
project(TinyUI)

set(CMAKE_CXX_STANDARD 17)

add_library(TinyUI SHARED TinyUI.cpp TinyUI.h)
