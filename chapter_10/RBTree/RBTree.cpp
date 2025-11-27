#include "RBTree.h"
#include <iostream>
#include <string>

template<typename E>
RBTree<E>::RBTree() : ST() { }

template<typename E>
typename RBTree<E>::Iterator RBTree<E>::insert(const K& k, const V& x) {
    TPos v = ST::inserter(k, x);
    if (v == ST::root()) {
        (*v).setColor(BLACK);
    } else {
        (*v).setColor(RED);
        remedyDoubleRed(v);
    }
    return Iterator(v);
}

template<typename E>
typename RBTree<E>::TPos RBTree<E>::sibling(const TPos& v) {
    TPos parent = v.parent();
    if (parent.left() == v)
        return parent.right();
    else
        return parent.left();
}

template<typename E>
bool RBTree<E>::wasParentRed(const TPos& v) {
    if (v.isExternal()) {
        TPos parent = v.parent();
        if (parent.v != nullptr && !parent.isExternal()) {
            return (*parent).isRed();
        }
    }
    return false;
}

template<typename E>
typename RBTree<E>::TPos RBTree<E>::restructure(const TPos& v) {
    TPos x = v;
    TPos y = x.parent();
    TPos z = y.parent();
    
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
        if (zParent.left() == z)
            zParent.v->left = b.v;
        else
            zParent.v->right = b.v;
        b.v->par = zParent.v;
    } else {
        // z 是根節點，設定 b 為新根
        // 不直接存取 _root，而是讓 b 的 parent 為 nullptr
        b.v->par = nullptr;
        // 注意：這裡可能需要更新 SearchTree 的根節點引用
        // 但由於我們無法直接存取，這裡的實作可能需要調整
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
    
    return b;
}

template<typename E>
void RBTree<E>::remedyDoubleRed(const TPos& z) {
    TPos v = z.parent();
    if (v == ST::root() || (*v).isBlack()) return;
    
    TPos w = sibling(v);
    
    if (w.isExternal() || (*w).isBlack()) {
        TPos x = restructure(z);
        (*x).setColor(BLACK);
        if (!x.left().isExternal()) (*x.left()).setColor(RED);
        if (!x.right().isExternal()) (*x.right()).setColor(RED);
    } else {
        (*v).setColor(BLACK);
        (*w).setColor(BLACK);
        TPos u = v.parent();
        if (u != ST::root()) {
            (*u).setColor(RED);
            remedyDoubleRed(u);
        }
    }
}

template<typename E>
void RBTree<E>::erase(const K& k) throw(NonexistentElement) {
    TPos u = ST::finder(k, ST::root());
    if (Iterator(u) == ST::end())
        throw NonexistentElement("Erase of nonexistent key");
    
    TPos r = ST::eraser(u);
    if (r == ST::root() || r.isExternal()) {
        if (!r.isExternal())
            (*r).setColor(BLACK);
        return;
    }
    
    if ((*r).isRed())
        (*r).setColor(BLACK);
    else
        remedyDoubleBlack(r);
}

template<typename E>
void RBTree<E>::erase(const Iterator& p) {
    // 透過 key 呼叫另一個 erase 方法
    K key = (*p).key();
    erase(key);
}

template<typename E>
void RBTree<E>::remedyDoubleBlack(const TPos& r) {
    TPos x = r.parent();
    TPos y = sibling(r);
    
    if (y.isExternal() || (*y).isBlack()) {
        bool yLeftRed = !y.left().isExternal() && (*y.left()).isRed();
        bool yRightRed = !y.right().isExternal() && (*y.right()).isRed();
        
        if (yLeftRed || yRightRed) {
            TPos z = yLeftRed ? y.left() : y.right();
            Color oldColor = (*x).color();
            TPos b = restructure(z);
            (*b).setColor(oldColor);
            if (!b.left().isExternal()) (*b.left()).setColor(BLACK);
            if (!b.right().isExternal()) (*b.right()).setColor(BLACK);
        } else {
            (*y).setColor(RED);
            if ((*x).isBlack() && x != ST::root()) {
                remedyDoubleBlack(x);
            } else {
                (*x).setColor(BLACK);
            }
        }
    } else {
        TPos z = (y == x.left() ? y.left() : y.right());
        restructure(z);
        (*y).setColor(BLACK);
        (*x).setColor(RED);
        remedyDoubleBlack(r);
    }
}

template class RBTree<Entry<int, std::string>>;

int main() {
    RBTree<Entry<int, std::string>> rbTree;
    
    std::cout << "=== Red-Black Tree Demo ===" << std::endl;
    
    std::cout << "\nInserting elements: 10, 20, 30, 15, 25, 5..." << std::endl;
    rbTree.insert(10, "Ten");
    rbTree.insert(20, "Twenty");
    rbTree.insert(30, "Thirty");
    rbTree.insert(15, "Fifteen");
    rbTree.insert(25, "TwentyFive");
    rbTree.insert(5, "Five");
    
    std::cout << "\nRB Tree contents (in-order):" << std::endl;
    for (auto it = rbTree.begin(); it != rbTree.end(); ++it) {
        std::cout << "Key: " << (*it).key() << ", Value: " << (*it).value() << std::endl;
    }
    
    std::cout << "\nErasing key 20..." << std::endl;
    try {
        rbTree.erase(20);
        std::cout << "Successfully erased key 20" << std::endl;
    } catch (const NonexistentElement&) {
        std::cout << "Error: Erase failed" << std::endl;
    }
    
    std::cout << "\nRB Tree contents after erasing 20:" << std::endl;
    for (auto it = rbTree.begin(); it != rbTree.end(); ++it) {
        std::cout << "Key: " << (*it).key() << ", Value: " << (*it).value() << std::endl;
    }
    
    std::cout << "\n=== Red-Black Tree Demo Completed ===" << std::endl;
    return EXIT_SUCCESS;
}