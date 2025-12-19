
// Entry class for storing key-value pairs
template<typename K, typename V>
class Entry {
private:
    K _key;
    V _value;
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setValue(const V& v) { _value = v; }
};

