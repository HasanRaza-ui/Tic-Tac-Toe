cmake_minimum_required(VERSION 3.14)
project(TicTacToe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ---- Sources ----
# Change these if your structure differs
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/Player.cpp
)

add_executable(tic_tac_toe ${SOURCES})

target_include_directories(tic_tac_toe PRIVATE include)
