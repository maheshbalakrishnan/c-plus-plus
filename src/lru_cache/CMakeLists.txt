cmake_minimum_required(VERSION 3.7)

project(lrucachelib)

add_library(${PROJECT_NAME} SHARED
    lru_cache.cxx
)

target_include_directories(${PROJECT_NAME} PRIVATE ./../include/)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_BINARY_DIR}
)