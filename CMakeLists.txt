cmake_minimum_required(VERSION 3.30)
project(terminal_todo_in_c C)

set(CMAKE_C_STANDARD 99)

add_executable(terminal_todo_in_c
        src/main.c
        src/modules/menu/menu.c
        src/modules/ui/ui.c
        src/modules/task/task.c
        src/modules/db/db.c
)
