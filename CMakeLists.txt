cmake_minimum_required(VERSION 3.7)

project(Practice)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

include_directories(src/include)
include_directories(src/include/external)

# build all the libraries
add_library(lru_cache SHARED
                 src/include/lru_cache/lru_cache.hpp
                 src/lru_cache/lru_cache.cxx)
set_property(TARGET lru_cache PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(autocomplete SHARED
                 src/include/autocomplete/autocomplete.hpp
                 src/autocomplete/autocomplete.cxx)
set_property(TARGET autocomplete PROPERTY POSITION_INDEPENDENT_CODE ON)

add_compile_options(-Wall -Wextra -shared)

# build all test executables
add_executable(lru_cache_test src/test/lru_cache_test.cpp)
target_link_libraries(lru_cache_test lru_cache)

add_executable(autocomplete_test src/test/autocomplete_test.cpp)
target_link_libraries(autocomplete_test autocomplete)

# add all test cases
add_test(LRU_CACHE_TEST  lru_cache_test) 
add_test(AUTO_COMPLETE_TEST  autocomplete_test) 

set_target_properties(lru_cache_test autocomplete_test PROPERTIES CXX_STANDARD 14)