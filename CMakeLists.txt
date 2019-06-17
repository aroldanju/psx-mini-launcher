cmake_minimum_required(VERSION 3.12)
project(psx-mini-launcher)

set(CMAKE_CXX_STANDARD 11)

add_executable(psx-mini-launcher src/main.cpp src/Connection.cpp)
# target_link_libraries(psx-mini-launcher)