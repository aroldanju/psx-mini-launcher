cmake_minimum_required(VERSION 3.12)
project(psx-mini-launcher)

set(EXECUTABLE_OUTPUT_PATH ../build/)
set(CMAKE_CXX_STANDARD 11)

add_executable(psx-mini-launcher src/main.cpp src/Connection.cpp src/Launcher.cpp src/Image.cpp src/Label.cpp src/Game.cpp src/Button.cpp)
target_link_libraries(psx-mini-launcher -lSDL2 -lSDL2_ttf -lSDL2_image -ltinyxml2)