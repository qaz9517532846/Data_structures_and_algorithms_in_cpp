#include <iostream>

template<typename K, typename V>
class Entry {
    public:
        typedef K Key;
        typedef V Value;
    public:
        Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) { }
        const K& key()      const { return _key; }
        const V& value()    const { return _value; }
        void setKey(const K& k) { _key = k; }
        void setValue(const V& v) { _value = v; }
    private:
        K _key;
        V _value;
};

template<typename BaseE>
class AVLEntry : public BaseE {
    private:
        int ht;
    protected:
        typedef typename BaseE::Key K;
        typedef typename BaseE::Value V;
        int height() const { return ht; }
        void setHeight(int h) { ht = h; }
    public:
        AVLEntry(const K& k = K(), const V& v = V())
            : BaseE(k, v), ht(0) { }
        template<typename> friend class AVLTree;
};

// 顏色枚舉
enum Color { RED, BLACK };

// RBEntry 類別定義
template<typename E>
class RBEntry : public E {
private:
    Color col;
protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
public:
    RBEntry(const K& k = K(), const V& v = V()) : E(k, v), col(RED) { }
    
    Color color() const { return col; }
    bool isRed() const { return col == RED; }
    bool isBlack() const { return col == BLACK; }
    void setColor(Color c) { col = c; }
    
    template<typename> friend class RBTree;
};
