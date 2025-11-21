#include "../SearchTree.h"

template<typename E>
class AVLTree : public SearchTree< AVLEntry<E> > {
    public:
        typedef AVLEntry<E> AE;
        typedef typename SearchTree<AE>::Iterator Iterator;
    protected:
        typedef typename AE::Key K;
        typedef typename AE::Value V;
        typedef SearchTree<AE> ST;
        typedef typename ST::TPos TPos;
    public:
        AVLTree();
        Iterator insert(const K& k, const V& x);
        void erase(const K& k) throw(NonexistentElement);
        void erase(const Iterator& p);
    protected:
        int height(const TPos& v) const;
        void setHeight(TPos v);
        bool isBalanced(const TPos& v) const;
        TPos tallGrandchild(const TPos& v) const;
        // trinode restructure wrapper — delegate to underlying BinaryTree
        void rebalance(const TPos& v);
        TPos restructure(TPos x);
};