cmake_minimum_required(VERSION 3.7)

project(lrucachelib)

add_library(${PROJECT_NAME} SHARED
    lru_cache.cxx
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ./../include/lru_cache/lru_cache.hpp)
target_include_directories(${PROJECT_NAME} PRIVATE ./../include/)

message(STATUS "library: ${CMAKE_INSTALL_LIBDIR}")

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_BINARY_DIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/include/)