#include<unordered_map>
#include<list>

using namespace std;

typedef std::list<string>::iterator UsageListIterator;

template <class T> class LRUCache {
    typedef std::pair<UsageListIterator, T> CacheValue;
private:
    unordered_map<string, CacheValue> mCache;
    list<string> mUsageList;
    double mCapacity;
    /**
     * Gets the least recently used item in the cache.
     * Returns a key in the cache
     */
    string getLRU();

    /**
     * Evicts a key from the cache
     */
    void evictKey(string);

    /**
     * Records the usage of the key, decreasing the 
     * likelihood of the key being evicted next
     */
    UsageListIterator recordKeyUsage(string);

    UsageListIterator recordKeyUsage(string, UsageListIterator);

public:
    /**
     * default constrcutor
     */
    LRUCache(double);

    /**
     * destructor
     */
    ~LRUCache();

    /**
     * Performs a get using the key provided.
     * Returns a null if not found
     */
    bool get(string key, T& value);

    /**
     * Inserts a new key-value pair into the cache
     * Returns nothing
     */
    bool put(string key, T value);

};