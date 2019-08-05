#include<iostream>
#include "common.hpp"
#include "data.hpp"
#include "lru_cache/lru_cache.hpp"

using namespace std;

/*
 * Constructor which takes in the maximum capacity of the cache
 */
template <class T>
LRUCache<T>::LRUCache(double capacity) : mCapacity(capacity) {
    cout << "Constructing LRUCache\n";
}

/*
 * destructor
 */
template <class T>
LRUCache<T>::~LRUCache() {
    cout << "Destructing LRUCache\n";
}

template <class T>
bool LRUCache<T>::getCacheValue(string key, CacheValue& value) {
    if (mCache.find(key) == mCache.end()) {
        return false;
    }
    value = mCache.at(key);
    return true;
}


/**
 * Returns the value if found in the cache, returns
 * nullptr otherwise
 */
template <class T> bool LRUCache<T>::get(string key, T& value) {
    CacheValue cacheValue;
    if (!this->getCacheValue(key, cacheValue)) {
        return false;
    }
    auto usageQueueRecord = recordKeyUsage(key);
    CacheValue insertValue = { usageQueueRecord, value };
    CacheKVPair insertPair = { key, insertValue };
    mCache.insert(insertPair);
    value = cacheValue.second;
    return true;
}

/**
 * Inserts a new key into the cache or updates an existing key 
 * with a new value
 */
template <class T>
bool LRUCache<T>::put(string key, T value) {
    if(mCapacity == mCache.size()) {
        // capacity reached, evict!
        if(!evictKey(getLRU())) {
            return false;
        }
    }
    auto usageQueueRecord = recordKeyUsage(key);
    CacheValue insertValue = { usageQueueRecord, value };
    CacheKVPair insertPair = { key, insertValue };
    mCache.insert(insertPair);
    return true;
}

/**
 * Returns the key that is least recently used.
 * If cache is empty, returns empty string
 */
template <class T> string LRUCache<T>::getLRU() {
    if(mUsageList.size() <= 0) {
        return "";
    }
    string key = mUsageList.back();
    mUsageList.pop_back();
    return key;
}

/**
 * Removes a key from the cache
 */
template <class T> bool LRUCache<T>::evictKey(string key) {
    CacheValue value;
    if(!getCacheValue(key, value)) {
        return false;
    }
    mUsageList.erase(value.first);
    mCache.erase(key);
    return true;
}

/**
 * Records the usage of a new key
 */
template <class T>
UsageListIterator LRUCache<T>::recordKeyUsage(string key) {
    mUsageList.push_front(key);
    return mUsageList.end();
}

/**
 * Records the usage of an existing key
 */
template <class T>
UsageListIterator LRUCache<T>::recordKeyUsage(string key, UsageListIterator it) {
    mUsageList.erase(it);
    return recordKeyUsage(key);
}

void temp() {
    LRUCache<int> lruCache(100);
    lruCache.put("asd", 1);
    int a;
    lruCache.get("asd", a);

}