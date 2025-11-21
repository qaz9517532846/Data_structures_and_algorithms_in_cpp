#include <iostream>
#include <list>
#include "Entry.h"

using namespace std;

template<typename E>
class BinaryTree {
    template<typename> friend class AVLTree;  // 加入這行
    protected:
        struct Node {
            E elt;
            Node* par;
            Node* left;
            Node* right;
            Node() : elt(), par(NULL), left(NULL), right(NULL) { }
        };
    public:
        class Position {
            public:
                Node* v;
                Position(Node* vv = nullptr) : v(vv) { }
                bool isExternal() const { return v->left == nullptr && v->right == nullptr; }
                bool isInternal() const { return !isExternal(); }
                Position left() const { return Position(v->left); }
                Position right() const { return Position(v->right); }
                Position parent() const { return Position(v->par); }
                E& operator*() { return v->elt; }            // change 'elt' if your Node uses a different name
                const E& operator*() const { return v->elt; } // change 'elt' if needed
                bool operator==(const Position& p) const { return v == p.v; }
                bool operator!=(const Position& p) const { return v != p.v; }
        };
        typedef std::list<Position> PositionList;
    public:
        BinaryTree();
        int size() const;
        bool empty() const;
        Position root() const;
        PositionList positions() const;
        void addRoot();
        void expandExternal(const Position& p);
        Position removeAboveExternal(const Position& p);

    private:
        Node* _root;
        int n;
        void preorder(Node* v, PositionList& pl) const;
};