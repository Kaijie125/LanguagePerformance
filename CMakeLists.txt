cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0002 NEW)
project(mi_proyecto C CXX CUDA)  

find_package(Java REQUIRED)
include(UseJava)

add_subdirectory(analisis_basico)

add_subdirectory(algoritmos)

add_subdirectory(img_bmp)

configure_file(random_gen.py random_gen.py COPYONLY)