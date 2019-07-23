cmake_minimum_required (VERSION 3.7)
project (practice)

set(CMAKE_CXX_STANDARD 11)

# include dirs
include_directories(src/include)
include_directories(src/include/external)

# configure the build
add_compile_options(-Wall -Wextra)

add_executable(${PROJECT_NAME} src/main.cxx)
add_executable(lru_cache src/lru_cache/lru_cache.cxx)