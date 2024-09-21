# CMakeList.txt : CMake project for Loggey, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.30)

project ("Loggey")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ext/fast_io/include)

# Add source to this project's executable.
add_executable (Loggey "example/Example1.cpp" "include/Loggey.hpp")

# TODO: Add tests and install targets if needed.
