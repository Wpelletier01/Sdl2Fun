set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-std=c++17 -ggdb3")
set (CMAKE_SHARED_LINKER_FLAGS "-v")

cmake_minimum_required(VERSION 3.12)
project(fun_sdl)


# Include directories
include_directories(include)

# Automatically find all source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Automatically find all header files in the include/my_lib directory
file(GLOB_RECURSE HEADERS "include/*.h")

# Required lib
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(fun_sdl main.cpp ${SOURCES} ${HEADERS})

target_include_directories(fun_sdl PUBLIC include${SDL2_INCLUDE_DIRS})
target_link_libraries(fun_sdl ${SDL2_LIBRARIES} SDL2_image)