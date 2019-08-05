#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "data.hpp"
#include "lru_cache/lru_cache.hpp"

using namespace std;

TEST_CASE( "Basic function of cache class", "[LRU Cache]") {
    LRUCache<int> uut(100.0);
    uut.put("1", 1);
    uut.put("2", 2);
    uut.put("3", 3);
    uut.put("4", 4);
    uut.put("5", 5);
}
