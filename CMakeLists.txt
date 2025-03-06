cmake_minimum_required(VERSION 3.30)
project(CTasker C)

set(CMAKE_C_STANDARD 99)

add_executable(CTasker
        src/main.c
        src/lib/todo.c
)
