#include "LinkedBinaryTree.h"

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) { }

int LinkedBinaryTree::size() const {
    return n;
}

bool LinkedBinaryTree::empty() const {
    return n == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const {
    return Position(_root);
}

void LinkedBinaryTree::addRoot() {
    if (_root != NULL) return; // tree already has a root
    _root = new Node;
    n = 1;
}

void LinkedBinaryTree::expandExternal(const Position& p) {
    Node* v = p.v;
    if (v->left != NULL || v->right != NULL) return; // not an external node
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    Node* v = w->par;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        sib->par = NULL;
    }
    else {
        Node* gpar = v->par;
        if (v == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return pl;
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL) preorder(v->left, pl);
    if (v->right != NULL) preorder(v->right, pl);
}

int main() {
    LinkedBinaryTree tree;
    tree.addRoot();
    LinkedBinaryTree::Position root = tree.root();
    *root = 1; // Set root element

    tree.expandExternal(root);
    LinkedBinaryTree::Position leftChild = root.left();
    LinkedBinaryTree::Position rightChild = root.right();
    *leftChild = 2; // Set left child element
    *rightChild = 3; // Set right child element

    tree.expandExternal(leftChild);
    LinkedBinaryTree::Position leftLeftChild = leftChild.left();
    LinkedBinaryTree::Position leftRightChild = leftChild.right();
    *leftLeftChild = 4; // Set left-left child element
    *leftRightChild = 5; // Set left-right child element

    // Print all positions in preorder
    LinkedBinaryTree::PositionList positions = tree.positions();
    for (auto& pos : positions) {
        cout << *pos << " ";
    }
    cout << endl;

    // Remove above external node
    tree.removeAboveExternal(leftLeftChild);

    // Print all positions after removal
    positions = tree.positions();
    for (auto& pos : positions) {
        cout << *pos << " ";
    }
    cout << endl;

    return 0;
}