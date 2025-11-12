#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename E, typename C>
class AdapterPriorityQueue {
    protected:
        typedef std::list<E> ElementList;
    public:
        class Position {
            private:
                typename ElementList::iterator q;
            public:
                E& operator*() { return *q; }
                const E& operator*() const { return *q; }
                friend class AdapterPriorityQueue;
        };
    public:
        int size() const;
        bool empty() const;
        const E& min();
        Position insert(const E& e);
        void removeMin();
        void remove(const Position& p);
        Position replace(const Position& p, const E& e);
    private:
        ElementList L;
        C isLess;
};