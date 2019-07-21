#include <iostream>
#include <vector>
#include "common.hpp"
#include "data.hpp"
#include "lru_cache/lru_cache.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    UNUSED(argc)
    UNUSED(argv)
    LRUCache<Data> lruCache(100);
    return 0;
}