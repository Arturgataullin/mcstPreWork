cmake_minimum_required(VERSION 3.28)
project(mcstStaj)

set(CMAKE_CXX_STANDARD 14)

include_directories("parser")

add_executable(mcstStaj
        "parser/parser.cpp"
        "parser/parser.h"
        "main.cpp"
        "logic_statement_parts/operand.h"
        "logic_statement_parts/logic_operand.h")
