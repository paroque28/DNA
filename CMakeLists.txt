cmake_minimum_required(VERSION 3.2)
add_definitions ("-Wall")
#Generator

project(DNASequenceGenerator)


set(SOURCE_GENERATE Generator/generator_main.c)
add_executable(DNASequenceGenerator ${SOURCE_GENERATE} Constants/constants.h)

#Alignment

project(DNASequenceAlignment)

set(SOURCE_ALIGN Alignment/alignment_main.c)
add_executable(DNASequenceAlignment ${SOURCE_ALIGN} Alignment/alignment.h Alignment/alignment.c Constants/constants.h)