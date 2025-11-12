#include "PriorityQueues.h"
#include "../Comparators.h"

template<typename E, typename C> //number of elements
int AdapterPriorityQueue<E, C>::size() const {
    return L.size();
}

template<typename E, typename C> // is the queue empty?
bool AdapterPriorityQueue<E, C>::empty() const {
    return size() == 0;
}

template<typename E, typename C> //minimum element
const E& AdapterPriorityQueue<E, C>::min() {
    auto minIt = L.begin();
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (isLess(*it, *minIt)) {
            minIt = it;
        }
    }
    return *minIt;
}

template<typename E, typename C> // insert element
typename AdapterPriorityQueue<E, C>::Position AdapterPriorityQueue<E, C>::insert(const E& e) {
    typename ElementList::iterator p = L.begin();
    while (p != L.end() && isLess(*p, e)) {
        ++p;
    }
    L.insert(p, e);
    Position pos;
    pos.q = --p; // set iterator to the newly inserted element
    return pos;
}

template<typename E, typename C> // remove minimum
void AdapterPriorityQueue<E, C>::removeMin() {
    if (L.empty()) return;
    auto minIt = L.begin();
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (isLess(*it, *minIt)) {
            minIt = it;
        }
    }
    L.erase(minIt);
}

template<typename E, typename C> // remove element at position p
void AdapterPriorityQueue<E, C>::remove(const Position& p) {
    L.erase(p.q);
}

template<typename E, typename C> // replace element at position p with e
typename AdapterPriorityQueue<E, C>::Position AdapterPriorityQueue<E, C>::replace(const Position& p, const E& e) {
    L.erase(p.q);
    return insert(e);
}

int main() {
    AdapterPriorityQueue<int, std::less<int>> apq;

    apq.insert(30);
    apq.insert(10);
    apq.insert(20);
    apq.insert(5);
    apq.insert(15);

    std::cout << "Minimum element: " << apq.min() << std::endl;

    apq.removeMin();
    std::cout << "Minimum element after removing min: " << apq.min() << std::endl;

    return 0;
}