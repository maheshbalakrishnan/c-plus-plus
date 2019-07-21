#include<iostream>
#include "lru_cache/lru_cache.hpp"
using namespace std;

template <class T> LRUCache<T>::LRUCache(double capacity) : mCapacity(capacity) {
    cout << "Constructing LRUCache\n";
}

template <class T> LRUCache<T>::~LRUCache() {
    cout << "Destructing LRUCache\n";
}

template <class T> T LRUCache<T>::get(string key) {
    return this->mCache.get(key);
}

template <class T> void LRUCache<T>::insert(string key, T value) {
    this->mCache.insert(key, value);
}