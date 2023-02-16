cmake_minimum_required(VERSION 3.0.0)
project(my_leetcode_learning VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(my_leetcode_learning 数组/01二叉树.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
