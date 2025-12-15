cmake_minimum_required(VERSION 3.10.0)
project(ABC341 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(ABC341 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
