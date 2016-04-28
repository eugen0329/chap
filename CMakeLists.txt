cmake_minimum_required(VERSION 2.8.3)
project(chat)

set(TARGET "ping")

file(GLOB_RECURSE SRC_NAMES src/*.c)

add_executable(${TARGET} ${SRC_NAMES})

