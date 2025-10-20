#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "../stackEmptyException.h"

template <typename E>
class ArrayStack {
    enum {DEFAULT_CAPACITY = 100};
    public:
        int size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& ele);
        void pop();
        ArrayStack(int stackSize = DEFAULT_CAPACITY);
        ~ArrayStack();

    private:
        int CURRENT_CAPACITY;
        int TOTAL_CAPACITY;
        E* stack;
        int t;
};

#endif