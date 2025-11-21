#include "AVLTree.h"
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>

template<typename E>
AVLTree<E>::AVLTree() : ST() { }

template<typename E>
int AVLTree<E>::height(const TPos& v) const {
    return (v.isExternal() ? 0 : (*v).height());
}

template<typename E>
void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.left());
    int hr = height(v.right());
    (*v).setHeight(1 + std::max(hl, hr));
}

template<typename E>
bool AVLTree<E>::isBalanced(const TPos& v) const {
    if (v.isExternal()) return true;
    
    int hl = height(v.left());
    int hr = height(v.right());
    return std::abs(hl - hr) <= 1;
}

template<typename E>
typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    if (z.isExternal()) return z;
    
    TPos y = (height(z.left()) >= height(z.right()) ? z.left() : z.right());
    
    if (y.isExternal()) return y;
    
    return (height(y.left()) >= height(y.right()) ? y.left() : y.right());
}

template<typename E>
void AVLTree<E>::rebalance(const TPos& v) {
    TPos z = v;
    
    if (z.v == nullptr) return;
    
    while (z != this->T.root()) {
        if (z.isExternal()) {
            z = z.parent();
            continue;
        }
        
        if (!isBalanced(z)) {
            TPos x = tallGrandchild(z);
            TPos y = restructure(x);        
            
            if (!y.left().isExternal()) setHeight(y.left());
            if (!y.right().isExternal()) setHeight(y.right());
            setHeight(y);
            
            break;
        }
        
        TPos parent = z.parent();
        if (parent.v == nullptr) break;
        
        z = parent;
    }
}

template<typename E>
typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    TPos v = ST::inserter(k, x);
    setHeight(v);
    rebalance(v);
    return Iterator(v);
}

template<typename E>
void AVLTree<E>::erase(const K& k) throw(NonexistentElement) {
    TPos v = ST::finder(k, ST::root());
    
    if(Iterator(v) == ST::end()) {
        throw NonexistentElement("Erase of nonexistent key");
    }
    
    TPos w = ST::eraser(v);
    rebalance(w);
}

template<typename E>
typename AVLTree<E>::TPos AVLTree<E>::restructure(TPos x) {
    if (x.v == nullptr) return TPos(nullptr);
    TPos y = x.parent();
    if (y.v == nullptr) return x;
    TPos z = y.parent();
    if (z.v == nullptr) return x;

    TPos a, b, c;
    TPos T0, T1, T2, T3;

    if (z.left() == y) {           
        if (y.left() == x) {
            a = x; b = y; c = z;
            T0 = x.left(); T1 = x.right(); T2 = y.right(); T3 = z.right();
        } else {
            a = y; b = x; c = z;
            T0 = y.left(); T1 = x.left(); T2 = x.right(); T3 = z.right();
        }
    } else {                       
        if (y.right() == x) {
            a = z; b = y; c = x;
            T0 = z.left(); T1 = y.left(); T2 = x.left(); T3 = x.right();
        } else {
            a = z; b = x; c = y;
            T0 = z.left(); T1 = x.left(); T2 = x.right(); T3 = y.right();
        }
    }
    
    TPos zParent = z.parent();
    
    if (zParent.v != nullptr) {
        if (zParent.left() == z) {
            zParent.v->left = b.v;
        } else {
            zParent.v->right = b.v;
        }
        b.v->par = zParent.v;
    } else {
        this->T._root = b.v;
        b.v->par = nullptr;
    }
    
    b.v->left = a.v;
    b.v->right = c.v;
    
    a.v->par = b.v;
    c.v->par = b.v;
    
    a.v->left = T0.v;
    a.v->right = T1.v;
    c.v->left = T2.v;
    c.v->right = T3.v;
    
    if (T0.v != nullptr) T0.v->par = a.v;
    if (T1.v != nullptr) T1.v->par = a.v;
    if (T2.v != nullptr) T2.v->par = c.v;
    if (T3.v != nullptr) T3.v->par = c.v;
    
    setHeight(a);
    setHeight(c); 
    setHeight(b);
    
    return b;
}

int main() {
    AVLTree<Entry<int, std::string>> avlTree;
    
    std::cout << "=== AVL Tree Demo ===" << std::endl;

    std::cout << "\nInserting elements: 20, 10, 30, 5, 15, 25, 35..." << std::endl;
    avlTree.insert(20, "Twenty");
    avlTree.insert(10, "Ten");
    avlTree.insert(30, "Thirty");
    avlTree.insert(5, "Five");
    avlTree.insert(15, "Fifteen");
    avlTree.insert(25, "TwentyFive");
    avlTree.insert(35, "ThirtyFive");

    std::cout << "\nAVL Tree contents (in-order):" << std::endl;
    for (auto it = avlTree.begin(); it != avlTree.end(); ++it) {
        std::cout << "Key: " << (*it).key() << ", Value: " << (*it).value() << std::endl;
    }
    
    std::cout << "\nSearching for keys 15, 25, 99:" << std::endl;
    std::vector<int> searchKeys = {15, 25, 99};
    for (int key : searchKeys) {
        auto it = avlTree.find(key);
        if (it != avlTree.end()) {
            std::cout << "Found - Key: " << key << ", Value: " << (*it).value() << std::endl;
        } else {
            std::cout << "Key " << key << " not found" << std::endl;
        }
    }
    
    std::cout << "\nErasing key 20..." << std::endl;
    avlTree.erase(20);

    std::cout << "\nAVL Tree contents after erasing 20:" << std::endl;
    for (auto it = avlTree.begin(); it != avlTree.end(); ++it) {
        std::cout << "Key: " << (*it).key() << ", Value: " << (*it).value() << std::endl;
    }

    auto it = avlTree.find(20);
    std::cout << "\nVerification - Key 20 " << (it == avlTree.end() ? "not found (successfully removed)" : "still exists") << std::endl;
    
    std::cout << "\n=== AVL Tree Demo Completed Successfully ===" << std::endl;
    return EXIT_SUCCESS;
}