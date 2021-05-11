cmake_minimum_required(VERSION 3.17)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)


add_executable(Lab2 main.cpp DynamicArray.h LinkedList.h Sequence.h ListSequence.h ArraySequence.h vector.h DiagonalMatrix.h MenuDiagonalMatrix.h MenuVector.h Test_DA_LL.h Test_AS_LLS.h MenuFull.h Test_AS_LLS.cpp Test_DA_LL.cpp Test_Matrix_Vector.cpp Test_Matrix_Vector.h Tests_full.h)
