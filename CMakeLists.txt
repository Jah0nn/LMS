cmake_minimum_required(VERSION 3.29)
project(lms)

set(CMAKE_CXX_STANDARD 20)

add_executable(lms main.cpp
        Student.h
        Course.h
        LMS.h
        Student.cpp
        Course.cpp
        LMS.cpp)
