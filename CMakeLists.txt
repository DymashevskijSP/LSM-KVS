cmake_minimum_required(VERSION 3.17)
project(KVS)

set(CMAKE_CXX_STANDARD 17)
file(GLOB H "include/*")
file(GLOB CPP "src/*")
add_library(LSM_KVS ${CPP} ${H})
target_include_directories(LSM_KVS PUBLIC include)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} LSM_KVS)       kkib