#include <iostream>
#include <vector>
#include "../stackEmptyException.h"
#include "DLinkedListQueue.h"

typedef string Elem;

class DequeStack {
    public:
        DequeStack();
        int size() const;
        bool empty() const;
        const Elem& top() const throw(StackEmpty);
        void push(const Elem& e);
        void pop() throw(StackEmpty);
    private:
        LinkedDeque D;
        int n;
};