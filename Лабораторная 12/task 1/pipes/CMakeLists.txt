# Задание: Создать библиотеку pipes из read_pipe.c write_pipe.c

set(SOURCE_LIB read_pipe.c write_pipe.c)

add_library(pipes STATIC ${SOURCE_LIB})