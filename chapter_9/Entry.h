#include <iostream>

template<typename K, typename V>
class Entry {   //a(key, value) pair
    public:     //public functions
        Entry(const K& k = K(), const V& v = V()) : key(k), value(v)
        { } //constructor
        const K& key()      const { return key; } //get key
        const V& value()    const { return value; } //get value
        void setKey(const K& k) { key = k; } //set key
        void setValue(const V& v) { value = v; } //setvalue
    private: //private data
        K key; //key
        V value; //value
};