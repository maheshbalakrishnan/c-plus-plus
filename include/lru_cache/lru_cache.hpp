#include<unordered_map>

using namespace std;

template <class T>

class LRUCache {
private:
    unordered_map<string, T> mCache;

public:
    /**
     * default constrcutor
     */
    LRUCache();

    /**
     * destructor
     */
    ~LRUCache();

    /**
     * Performs a get using the key provided.
     * Returns a null if not found
     */
    T get(string key);

    /**
     * Inserts a new key-value pair into the cache
     * Returns nothing
     */
    void insert(string key, T value);

};