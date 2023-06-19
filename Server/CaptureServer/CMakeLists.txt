cmake_minimum_required(VERSION 3.5)

project(CaptureServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(Include)
set(SOURCES Src/framebuffer.cpp)
add_executable(CaptureServer ${SOURCES}  main.cpp)
