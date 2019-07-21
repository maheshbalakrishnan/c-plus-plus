/**
 *  Least recently used cache
 */

#include<lru_cache/lru_cache.hpp>
#include<iostream>
using namespace std;

LRUCache::LRUCache() {
    cout << "Constructing LRUCache\n";
}

LRUCache::~LRUCache() {
    cout << "Destructing LRUCache\n";
}

T LRUCache::get(string key) {
    return this->mCache.get(key);
}

void LRUCache::insert(string key, T value) {
    this->mCache.insert(key, value);
}