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
                const Elem& operator*() const { return v->elt; }
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

class EulerTour {
    protected:
        struct Result {
            int leftResult;
            int rightResult;
            int finalResult;
        };
        typedef LinkedBinaryTree BinaryTree;
        typedef typename LinkedBinaryTree::Position Position;
    protected:
        const LinkedBinaryTree* tree;
    public:
        void initialize(const LinkedBinaryTree& T) {
            tree = &T;
        }
    protected:
        int eulerTour(const Position& p) const;

        virtual void visitExternal(const Position& p, Result& r) const {}
        virtual void visitLeft(const Position& p, Result& r) const {}
        virtual void visitBelow(const Position& p, Result& r) const {}
        virtual void visitRight(const Position& p, Result& r) const {}
        Result initResult() const { return Result(); }
        int result(const Result& r) const { return r.finalResult; }
};

class EvaluateExpressionTour : public EulerTour
{
    protected:
        typedef typename EulerTour::BinaryTree BinaryTree;
        typedef typename EulerTour::Position Position;
        typedef typename EulerTour::Result Result;
    public:
        void execute(const BinaryTree& T) { //execute the tour
            initialize(T);
            std::cout << "The value is : " << eulerTour(T.root()) <<"\n";
        }
    protected: // leaf: returnvalue
        void visitExternal(const Position& p, Result& r) const
        { r.finalResult = *p.parent(); }

        void visitLeft(Position& p, Result& r) const
        { r.leftResult = *p.left(); } 

        void visitRight(Position& p, Result& r) const
        { r.rightResult = *p.right(); }
};

class PrintExpressionTour : public EulerTour
{
    protected:
        typedef typename EulerTour::BinaryTree BinaryTree;
        typedef typename EulerTour::Position Position;
        typedef typename EulerTour::Result Result;
    public:
        void execute(const LinkedBinaryTree& T) { //execute the tour
            initialize(T);
            cout << "Expression : ";
            eulerTour(T.root());
            cout << endl;
        }
    protected:
        void visitExternal(const Position& p, Result& r) const
        { cout << *p; }

        void visitLeft(const Position& p, Result& r) const
        { cout << "("; }

        void visitBelow(const Position& p, Result& r) const
        { cout << " " << *p << " "; }

        void visitRight(const Position& p, Result& r) const
        { cout << ")"; }
};