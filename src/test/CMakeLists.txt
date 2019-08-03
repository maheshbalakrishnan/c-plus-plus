cmake_minimum_required(VERSION 3.7)

find_package(Catch2 REQUIRED)

add_executable(LRU_CACHE_TEST lru_cache_test.cpp)

include_directories(../include/external)

target_link_libraries(LRU_CACHE_TEST 
                        Catch2::Catch2
                        ${CMAKE_BINARY_DIR}/liblrucachelib.so)

include(CTest)
include(Catch)
catch_discover_tests(LRU_CACHE_TEST)