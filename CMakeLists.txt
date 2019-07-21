cmake_minimum_required (VERSION 3.7)
project (practice)

set(CMAKE_CXX_STANDARD 11)

# include dirs
include_directories(src/include)

# configure the build
add_compile_options(-Wall -Wextra)

# what to build
file(GLOB SOURCES
    src/include/*.h
    src/*.cxx
)
add_executable(main ${SOURCES})