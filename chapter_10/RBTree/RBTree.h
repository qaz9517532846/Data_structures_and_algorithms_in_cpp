#ifndef RBTREE_H
#define RBTREE_H

#include "../SearchTree.h"
#include "../NonexistentElement.h"

// RBTree 類別
template<typename E>
class RBTree : public SearchTree<RBEntry<E>> {
public:
    typedef RBEntry<E> RBE;  // 改名避免衝突
    typedef typename SearchTree<RBE>::Iterator Iterator;
protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
    typedef SearchTree<RBE> ST;
    typedef typename ST::TPos TPos;
    
public:
    RBTree();
    Iterator insert(const K& k, const V& x);
    void erase(const K& k) throw(NonexistentElement);
    void erase(const Iterator& p);
    
protected:
    void remedyDoubleRed(const TPos& z);
    void remedyDoubleBlack(const TPos& r);
    TPos sibling(const TPos& v);
    TPos restructure(const TPos& v);
    bool wasParentRed(const TPos& v);
};

#endif