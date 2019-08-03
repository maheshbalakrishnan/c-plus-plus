#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "lru_cache/lru_cache.hpp"

TEST_CASE( "Basic function of cache class", "[LRU Cache]") {
    LRUCache<int> uut(100.0);
}
