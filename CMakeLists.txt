cmake_minimum_required(VERSION 3.23)
project(My_Assembly_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(My_Assembly_Project main.cpp opcode.h get_first_address.h pass1.h add_two_hexa.h pass2.h)
