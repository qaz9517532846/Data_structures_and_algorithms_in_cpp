#include <iostream>
#include <list>

using namespace std;

typedef int Elem;

class LinkedBinaryTree {
    protected:
        struct Node {
            Elem elt;
            Node* par;
            Node* left;
            Node* right;
            Node() : elt(), par(NULL), left(NULL), right(NULL) { }
        };
    public:
        class Position {
            private:
                Node* v;
            public:
                Position(Node* _v = NULL) : v(_v) { }
                Elem& operator*() { return v->elt; }
                Position left() const { return Position(v->left); }
                Position right() const { return Position(v->right); }
                Position parent() const { return Position(v->par); }
                bool isRoot() const { return v->par == NULL; }
                bool isExternal() const { return v->left == NULL && v->right == NULL; }
                friend class LinkedBinaryTree;
        };
        typedef std::list<Position> PositionList;
    public:
        LinkedBinaryTree();
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