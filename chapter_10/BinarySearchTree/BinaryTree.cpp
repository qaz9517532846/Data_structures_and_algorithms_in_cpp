#include "BinaryTree.h"

template<typename E>
BinaryTree<E>::BinaryTree() : _root(NULL), n(0) { }

template<typename E>
int BinaryTree<E>::size() const {
    return n;
}

template<typename E>
bool BinaryTree<E>::empty() const {
    return n == 0;
}

template<typename E>
typename BinaryTree<E>::Position BinaryTree<E>::root() const {
    return typename BinaryTree<E>::Position(_root);
}

template<typename E>
void BinaryTree<E>::addRoot() {
    if (_root != NULL) return; // tree already has a root
    _root = new typename BinaryTree<E>::Node;
    n = 1;
}

template<typename E>
void BinaryTree<E>::expandExternal(const typename BinaryTree<E>::Position& p) {
    typename BinaryTree<E>::Node* v = p.v;
    if (v->left != NULL || v->right != NULL) return; // not an external node
    v->left = new typename BinaryTree<E>::Node;
    v->left->par = v;
    v->right = new typename BinaryTree<E>::Node;
    v->right->par = v;
    n += 2;
}

template<typename E>
typename BinaryTree<E>::Position BinaryTree<E>::removeAboveExternal(const typename BinaryTree<E>::Position& p) {
    typename BinaryTree<E>::Node* w = p.v;
    typename BinaryTree<E>::Node* v = w->par;
    typename BinaryTree<E>::Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        if (sib) sib->par = NULL;
    }
    else {
        typename BinaryTree<E>::Node* gpar = v->par;
        if (v == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        if (sib) sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return typename BinaryTree<E>::Position(sib);
}

template<typename E>
typename BinaryTree<E>::PositionList BinaryTree<E>::positions() const {
    typename BinaryTree<E>::PositionList pl;
    preorder(_root, pl);
    return pl;
}

template<typename E>
void BinaryTree<E>::preorder(typename BinaryTree<E>::Node* v, typename BinaryTree<E>::PositionList& pl) const {
    pl.push_back(typename BinaryTree<E>::Position(v));
    if (v->left != NULL) preorder(v->left, pl);
    if (v->right != NULL) preorder(v->right, pl);
}

template class BinaryTree<Entry<int, std::string>>;