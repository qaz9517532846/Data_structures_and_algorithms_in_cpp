#include "Heap.h"

template<typename E, typename C> //number of elements
int HeapPriorityQueue<E, C>::size() const {
    return T.size();
}

template<typename E, typename C> // is the queue empty?
bool HeapPriorityQueue<E, C>::empty() const {
    return size() == 0;
}

template<typename E, typename C> //minimum element
const E& HeapPriorityQueue<E, C>::min() {
    return *(T.root());
} //return reference to root element

template<typename E, typename C> // insert element
void HeapPriorityQueue<E, C>::insert(const E& e) {
    T.addLast(e); //add e to heap
    Position v= T.last(); //e’s position
    while(!T.isRoot(v)) { //up-heap bubbling
        Position u =T.parent(v);
        if (!isLess(*v, *u)) break; // if v in order,we’ redone
        T.swap(v, u); // ...else swap with parent
        v = u;
    }
}

template<typename E, typename C> // remove minimum
void HeapPriorityQueue<E, C>::removeMin() {
    if (size() == 1) //only one node?
        T.removeLast(); // ...remove it
    else {
        Position u = T.root(); //root position
        T.swap(u, T.last()); //swap last with root
        T.removeLast(); // ...and remove last
        while(T.hasLeft(u)) { //down-heap bubbling
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u); //v is u’s smaller child
            if (isLess(*v, *u)) { // is u out of order?
                T.swap(u, v); // ...then swap
                u = v;
            }
            else break; //else we’re done
        }
    }
}

int main() {
    HeapPriorityQueue<int, std::less<int>> hpq;

    hpq.insert(30);
    hpq.insert(10);
    hpq.insert(20);
    hpq.insert(5);
    hpq.insert(15);

    std::cout << "Minimum element: " << hpq.min() << std::endl;

    while (!hpq.empty()) {
        std::cout << "Removing minimum element: " << hpq.min() << std::endl;
        hpq.removeMin();
    }

    return 0;
}