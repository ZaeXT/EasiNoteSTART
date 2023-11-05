cmake_minimum_required(VERSION 3.27)
project(ENS)
aux_source_directory(./src SRCS)

add_executable(${PROJECT_NAME} ${SRCS})