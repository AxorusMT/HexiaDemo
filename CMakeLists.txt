 cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Hexia VERSION 0.1)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(Hexia src/main.cpp src/glad/glad.c ${SRC_FILES})

target_link_libraries(Hexia SDL2 dl GL)
target_include_directories(Hexia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
