# Copyright (C) 2023-2024 by KikoMira
# Licensed under the MIT License

# OpenSML -- Open Scene Manager Library

# CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(OpenSML VERSION 3.1.5 LANGUAGES CXX)

set(source_files
    "src/scene.cpp"
    "src/scene.hpp"
)

add_library(OpenSML STATIC ${source_files})

target_include_directories(OpenSML PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
