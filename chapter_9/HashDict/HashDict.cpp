#include "../HashDict.h"

template<typename K, typename V, typename H>
HashDict<K,V,H>::HashDict(int capacity) : HashMap<K,V,H>(capacity) {}

template<typename K, typename V, typename H>
typename HashDict<K,V,H>::Iterator HashDict<K,V,H>::insert(const K& k, const V& v)
{
    Iterator p = this->finder(k); // find key
    Iterator q = this->inserter(p, Entry(k, v)); // insert it here
    return q; // return its position
}

template<typename K, typename V, typename H>
typename HashDict<K,V,H>::Range HashDict<K,V,H>::findAll(const K& k) {
    Iterator b = this->finder(k); // look up k
    
    // If key not found, return empty range [end, end)
    if (this->endOfBkt(b)) {
        return Range(b, b);
    }
    
    Iterator p = b;
    // Advance p to the first entry that doesn't match k
    // Use operator++ which properly handles bucket boundaries
    while (true) {
        ++p; // Move to next entry (handles bucket transitions)
        if (p == this->end() || (*p).key() != k) {
            break; // Stop when we reach end or find a different key
        }
    }
    
    return Range(b, p); // return range [b, p)
}

template class HashDict<string, int, HashString>;