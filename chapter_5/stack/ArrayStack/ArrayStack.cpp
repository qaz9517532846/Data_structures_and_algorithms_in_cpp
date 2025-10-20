#include <iostream>

#include "ArrayStack.h"

using namespace std;

template <typename E> 
ArrayStack<E>::ArrayStack(int stackSize) {
    stack = new E[stackSize];
    TOTAL_CAPACITY = stackSize;
    CURRENT_CAPACITY = 0;
    t = -1;
}

template <typename E> 
ArrayStack<E>::~ArrayStack() {
    delete[] stack;
}

template <typename E> 
int ArrayStack<E>::size() const {
    return t + 1;
}

template <typename E> 
bool ArrayStack<E>::empty() const {
    return t < 0;
}

template <typename E> 
const E& ArrayStack<E>::top() const {
    if( empty() )
        throw(StackEmpty("Stack is empty!"));
    return stack[t];
}

template <typename E> 
void ArrayStack<E>::push(const E& ele) {
    if(CURRENT_CAPACITY == TOTAL_CAPACITY)
        throw(StackEmpty("Stack is Full!"));
    else {
        ++t;
        stack[t] = ele;
        ++CURRENT_CAPACITY;
    }
    return;
}

template <typename E> 
void ArrayStack<E>::pop() {
    if (empty())
        throw (StackEmpty("Stack is Empty!"));

    --t;
    --CURRENT_CAPACITY;
}

template class ArrayStack<int>;
template class ArrayStack<std::string>; // or std::__cxx11::basic_string<...>