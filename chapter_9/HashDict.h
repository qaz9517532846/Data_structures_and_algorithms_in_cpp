#include "HashMap.h"

// ============================================================
// Range class template for iterator ranges
// ============================================================
template<typename K, typename V, typename H>
class Range {
private:
    typedef typename HashMap<K,V,H>::Iterator Iterator;
    Iterator _begin; // front of range
    Iterator _end;   // end of range
    
public:
    Range(const Iterator& b, const Iterator& e) // constructor
        : _begin(b), _end(e) {}
    Iterator& begin() { return _begin; } // get beginning
    Iterator& end() { return _end; }     // get end
};

// ============================================================
// HashDict class (Multimap implementation)
// ============================================================
template<typename K, typename V, typename H>
class HashDict : public HashMap<K,V,H> {
public:
    typedef typename HashMap<K,V,H>::Iterator Iterator;
    typedef typename HashMap<K,V,H>::Entry Entry;
    typedef ::Range<K,V,H> Range;  // Use global Range with :: prefix
    
public:
    HashDict(int capacity = 100); // constructor
    Range findAll(const K& k);    // find all entries with k
    Iterator insert(const K& k, const V& v); // insert pair (k,v)
};