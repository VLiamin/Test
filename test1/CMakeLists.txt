cmake_minimum_required(VERSION 3.23)
project(test1 C)
enable_language(ASM_NASM)

set(CMAKE_C_STANDARD 99)

add_executable(test1 main.c Compare.asm)
