cmake_minimum_required(VERSION 3.10.0)

project(ABC345 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(abc345 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
