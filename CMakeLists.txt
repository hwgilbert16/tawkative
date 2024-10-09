cmake_minimum_required(VERSION 3.16)
project(Tawkative)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./build")

add_subdirectory(apps/tawkative-server)
add_subdirectory(utils)