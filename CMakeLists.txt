cmake_minimum_required(VERSION 3.13)
project(GeneticAlgorithm_RankedElite C)

set(CMAKE_C_STANDARD 99)

add_library(generate gen_alg/generate.c)
add_executable(GeneticAlgorithm_RankedElite main.c gen_alg/print.c gen_alg/print.h gen_alg/mainlib.c gen_alg/mainlib.h)