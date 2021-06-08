cmake_minimum_required(VERSION 3.17)
project(Lab2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wa,-mbig-obj")
set(CMAKE_CXX_STANDARD 17)


add_executable(Lab2 main.cpp DynamicArray.h LinkedList.h Sequence.h ListSequence.h ArraySequence.h vector.h DiagonalMatrix.h MenuDiagonalMatrix.h MenuVector.h Test_catch.cpp catch.hpp)
