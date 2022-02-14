cmake_minimum_required(VERSION 3.21)
project(FileCounter1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(FileCounter1 main.cpp DataContainers/FinalResults.cpp
        DataContainers/FinalResults.h
        Search_directory.cpp Search_directory.h DataContainers/Work_parameters.cpp DataContainers/Work_parameters.h)


add_subdirectory(Google_tests)

