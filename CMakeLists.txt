cmake_minimum_required(VERSION 3.2)

project(DNASequenceGenerator)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_GENERATE Generator/main.c)
add_executable(DNASequenceGenerator ${SOURCE_GENERATE})

project(DNASequenceAlignment)

set(SOURCE_ALIGN Alignment/main.c)
add_executable(DNASequenceAlignment ${SOURCE_ALIGN})