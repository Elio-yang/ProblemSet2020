cmake_minimum_required(VERSION 3.17)
project(PROBLEMSET)

set(CMAKE_CXX_STANDARD 11)

add_executable(W2_Q1 homework/week2/W2_Q1.cpp)
add_executable(W3_Q1_n homework/week3/W3_Q1.cpp)
add_executable(p4913 lgOJ/p4913_bitree.cpp)

add_executable(W3_Q2 homework/week3/W3_Q2.cpp)
add_executable(W3_Q3 homework/week3/W3_Q3.cpp)
add_executable(W3_Q4 homework/week3/W3_Q4.cpp)

add_executable(queen dsacpp/queen/queen.h dsacpp/queen/queen_stk.h dsacpp/queen/main.cpp dsacpp/queen/func.cpp)
add_executable(queen_it dsacpp/queen/queen_it.h dsacpp/queen/main_it.cpp dsacpp/queen/func_it.cpp)
