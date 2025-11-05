#include <iostream>
#include <vector>
#include <list>
#include "../Point2D.h"

using namespace std;

class LeftRight {
    public:
        bool operator()(const Point2D& p, const Point2D& q) const {
            return p.getX() < q.getX();
        }
};

class BottomTop {
    public:
        bool operator()(const Point2D& p, const Point2D& q) const {
            return p.getY() < q.getY();
        }
};

template<typename E, typename C>
class ListPriorityQueue {
    public:
        int size() const; //number of elements
        bool empty() const; // is the queue empty?
        void insert(const E& e); // insert element
        const E& min() const; //minimum element
        void removeMin(); //remove minimum
        private:
        std::list<E> L; //priority queue contents
        C isLess; // less-than comparator
};

template<typename E, typename C> //number of elements
int ListPriorityQueue<E, C>::size() const {
    return L.size();
}

template<typename E, typename C> // is the queue empty?
bool ListPriorityQueue<E, C>::empty() const {
    return L.empty();
}

template<typename E, typename C> // insert element
void ListPriorityQueue<E, C>::insert(const E& e) {
    typename std::list<E>::iterator p;
    p = L.begin();
    while(p != L.end() && !isLess(e, *p)) ++p; //find larger element
    L.insert(p, e); // insert ebeforep
}

template<typename E, typename C> //minimum element
const E& ListPriorityQueue<E, C>::min() const
{
    return L.front();
} //minimumisat the front

template<typename E, typename C> //remove minimum
void ListPriorityQueue<E, C>::removeMin()
{
    L.pop_front();
}

int main() {
    ListPriorityQueue <Point2D, LeftRight> p2;

    p2.insert( Point2D(8.5, 4.6) );
    // add three points to p2
    p2.insert( Point2D(1.3, 5.7) );
    p2.insert( Point2D(2.5, 0.6) );

    while(!p2.empty()) {
        cout << "(" << p2.min().getX() << " ," << p2.min().getY() << ")" << endl;
        p2.removeMin();
    }

    return EXIT_SUCCESS;
}