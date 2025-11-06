#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef int Elem;

struct Node {
    Elem elt;
    Node* par;
    Node* left;
    Node* right;
    Node() : elt(), par(NULL), left(NULL), right(NULL) { }
};

class Position {
    private:
        Node* v;
    public:
        Position(Node* _v = NULL) : v(_v) { }
        Elem& operator*() { return v->elt; }
        const Elem& operator*() const { return v->elt; }
        Position left() const { return Position(v->left); }
        Position right() const { return Position(v->right); }
        Position parent() const { return Position(v->par); }
        bool isRoot() const { return v->par == NULL; }
        bool isExternal() const { return v->left == NULL && v->right == NULL; }
        friend class LinkedBinaryTree;
};

template<typename E>
class VectorCompleteTree : public Position {
    private:
        std::vector<E> V; // underlying storage
    public:
        typedef typename std::vector<E>::iterator Position; //a position in the tree
    protected:
        Position pos(int i) //map an index to a position
            { return V.begin() + i; }

        int idx(const Position& p) const //map a position to an index
            { return p - V.begin(); }
    public:
        VectorCompleteTree() : V(1) { } //constructor
        int size() const { return V.size() - 1; }
        Position left(const Position& p) { return pos(2 * idx(p)); }
        Position right(const Position& p) { return pos(2 * idx(p) + 1); }
        Position parent(const Position& p) { return pos(idx(p) / 2); }
        bool hasLeft(const Position& p) const { return 2 * idx(p) <= size(); }
        bool hasRight(const Position& p) const { return 2 * idx(p) + 1 <= size(); }
        bool isRoot(const Position& p) const {return idx(p) == 1; }
        Position root() { return pos(1);}
        Position last() { return pos(size()); }
        void addLast(const E& e) { V.push_back(e); }
        void removeLast() { V.pop_back(); }
        void swap(const Position& p, const Position& q)
            {E e = *q; *q = *p; *p = e; }
};