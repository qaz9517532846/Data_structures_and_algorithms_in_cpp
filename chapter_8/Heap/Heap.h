#include "../CompleteTree.h"
#include "../Comparators.h"

template<typename E, typename C>
class HeapPriorityQueue {
    public:
        int size() const; //number of elements
        bool empty() const; // is the queue empty?
        void insert(const E& e); // insert element
        const E& min(); //minimum element
        void removeMin(); //remove minimum
    private:
        VectorCompleteTree<E> T; //priority queue contents
        C isLess; // less-than comparator
        //shortcut for treeposition
        typedef typename VectorCompleteTree<E>::Position Position;
};