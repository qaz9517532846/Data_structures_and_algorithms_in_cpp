#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Entry.h"

using namespace std;

// Hash function classes
class HashString {
public:
    size_t operator()(const string& s) const {
        size_t hash = 0;
        for (size_t i = 0; i < s.length(); i++) {
            hash = hash * 37 + s[i];
        }
        return hash;
    }
};

class HashInt {
public:
    size_t operator()(int k) const {
        return static_cast<size_t>(k);
    }
};

// HashMap class template
template<typename K, typename V, typename H>
class HashMap {
public:
    typedef Entry<K, V> Entry;
    class Iterator;
    
protected:  // Changed to protected for HashDict access
    typedef std::list<Entry> Bucket;
    typedef std::vector<Bucket> BktArray;
    typedef typename BktArray::iterator BItor;
    typedef typename Bucket::iterator EItor;
    
    int n;
    H hash;
    BktArray B;
    
    Iterator finder(const K& k);
    Iterator inserter(const Iterator& p, const Entry& e);
    void eraser(const Iterator& p);
    
    static void nextEntry(Iterator& p) {
        ++p.ent;
    }
    
    static bool endOfBkt(const Iterator& p) {
        return p.ent == p.bkt->end();
    }
    
public:
    HashMap(int capacity = 100);
    int size() const;
    bool empty() const;
    Iterator find(const K& k);
    Iterator put(const K& k, const V& v);
    void erase(const K& k);
    void erase(const Iterator& p);
    Iterator begin();
    Iterator end();
};

// Iterator class
template<typename K, typename V, typename H>
class HashMap<K, V, H>::Iterator {
private:
    EItor ent;
    BItor bkt;
    const BktArray* ba;
    
public:
    Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor()) 
        : ent(q), bkt(b), ba(&a) {}
    
    Entry& operator*() const;
    bool operator==(const Iterator& p) const;
    bool operator!=(const Iterator& p) const { return !(*this == p); }
    Iterator& operator++();
    
    friend class HashMap;
};