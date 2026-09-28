cmake_minimum_required(VERSION 3.10.0)
set(PROJECT_NAME ModpackCreator)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(external)
add_subdirectory(src)
