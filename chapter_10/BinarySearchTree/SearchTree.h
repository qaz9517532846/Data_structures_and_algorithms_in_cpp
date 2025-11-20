#include "BinaryTree.h"
#include "../NonexistentElement.h"

template<typename E>
class SearchTree {
    public:
        typedef typename E::Key K;
        typedef typename E::Value V;
        class Iterator;
    public:
        SearchTree();
        int size() const;
        bool empty() const;
        Iterator find(const K& k) const;
        Iterator insert(const K& k, const V& x);
        void erase(const K& k) throw(NonexistentElement);
        void erase(const Iterator& p);
        Iterator begin() const;
        Iterator end() const;
    protected:
        typedef BinaryTree<E> BinaryTree;
        typedef typename BinaryTree::Position TPos;
        TPos root() const;
        TPos finder(const K& k, const TPos& v) const;
        TPos inserter(const K& k, const V& x);
        TPos eraser(const TPos& v);
    protected:
        BinaryTree T;
        int n;
    public:
        class Iterator {
            private:
                TPos v;
            public:
                Iterator(const TPos& vv) : v(vv) { }
                const E& operator*() const { return *v; }
                E& operator*() { return *v; }
                E* operator->() { return &operator*(); }
                const E* operator->() const { return &operator*(); }
                bool operator==(const Iterator& p) const { return v == p.v; }
                bool operator!=(const Iterator& p) const { return !(*this == p); }
                Iterator& operator++();
                friend class SearchTree<E>;
        };
};