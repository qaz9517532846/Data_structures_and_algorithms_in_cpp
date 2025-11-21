#include "SearchTree.h"
#include <iostream>
#include <cstdlib>

template<typename E>
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++() {
    // inorder successor
    typename SearchTree<E>::TPos p = v;
    if (!p.right().isExternal()) {
        p = p.right();
        while (!p.left().isExternal()) p = p.left();
        v = p;
        return *this;
    }
    typename SearchTree<E>::TPos w = p.parent();
    while (!w.isExternal() && p == w.right()) {
        p = w;
        w = w.parent();
    }
    v = w;
    return *this;
}

template<typename E>
SearchTree<E>::SearchTree() : T(), n(0)
{
    T.addRoot();
    T.expandExternal(T.root());
}

template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::root() const {
    return T.root().left();
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::begin() const {
    typename SearchTree<E>::TPos v = root();
    while(v.isInternal()) v = v.left();
    return Iterator(v.parent());
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::end() const {
    return Iterator(T.root());
}

template<typename E>
int SearchTree<E>::size() const {
    return n;
}

template<typename E>
bool SearchTree<E>::empty() const {
    return n == 0;
}

template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v) const {
    if (v.isExternal()) return v;
    const K& vk = (*v).key();
    if (k < vk) return finder(k, v.left());
    else if (k > vk) return finder(k, v.right());
    else return v;
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k) const {
    typename SearchTree<E>::TPos v = finder(k, root());
    if (v.isExternal()) return end();
    return Iterator(v);
}

template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x) {
    typename SearchTree<E>::TPos v = finder(k, root());
    if (!v.isExternal()) return v; // key exists
    T.expandExternal(v);
    (*v).setKey(k);
    (*v).setValue(x);
    ++n;
    return v;
}

template<typename E>
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x) {
    typename SearchTree<E>::TPos v = inserter(k, x);
    return Iterator(v);
}

template<typename E>
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos v) {
    typename SearchTree<E>::TPos w;
    if (v.left().isExternal()) w = v.left();
    else if (v.right().isExternal()) w = v.right();
    else {
        // successor: leftmost in right subtree
        w = v.right();
        while (!w.left().isExternal()) w = w.left();
        typename SearchTree<E>::TPos u = w.parent();
        (*v).setKey((*u).key());
        (*v).setValue((*u).value());
        w = u.right();
    }
    --n;
    return T.removeAboveExternal(w);
}

template<typename E>
void SearchTree<E>::erase(const K& k) throw(NonexistentElement) {
    typename SearchTree<E>::TPos v = finder(k, root());
    if (v.isExternal()) {
        throw NonexistentElement("Erase of nonexistent element");
    }
    eraser(v);
}

template class SearchTree<Entry<int, std::string>>;
template class SearchTree<AVLEntry<Entry<int, std::string>>>;  // 加入這行