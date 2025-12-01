cmake_minimum_required(VERSION 3.0)
project(joc)

set(CMAKE_CXX_STANDARD 17)

# Locația instalării raylib (static) în home/inter
set(RAYLIB_ROOT "/home/iulia/inter/raylib")

add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${RAYLIB_ROOT}/src/libraylib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${RAYLIB_ROOT}/src"
)

add_executable(joc main.cpp)
target_link_libraries(joc
    raylib
    m
    pthread
    dl
    rt
    X11
    Xrandr
    Xi
)
