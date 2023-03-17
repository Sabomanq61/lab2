cmake_minimum_required(VERSION 3.24)
project(FileObserver)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(FileObserver main.cpp include/subject.h include/file_subject.h include/i_observer.h include/file_observer.h src/subject.cpp src/file_observer.cpp src/file_subject.cpp)
