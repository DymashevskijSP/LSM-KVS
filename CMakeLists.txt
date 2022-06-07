cmake_minimum_required(VERSION 3.17)
project(KVS)

set(CMAKE_CXX_STANDARD 17)
include_directories("include/")
add_executable(${PROJECT_NAME} main.cpp lsm_test.cpp src/ByteArrayImpl.cpp src/KeyValue.cpp src/log.cpp src/lsm.cpp src/SStable.cpp)