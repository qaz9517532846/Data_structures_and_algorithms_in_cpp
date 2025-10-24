#include "LinkedStack.h"

LinkedStack::LinkedStack() : S(), n(0)
{

}

int LinkedStack::size() const
{
    return n;
}

bool LinkedStack::empty() const
{
    return n == 0;
}

const Elem& LinkedStack::top() const throw(StackEmpty)
{
    if(empty()) throw StackEmpty("Top of empty stack");
    return S.front();
}

void LinkedStack::push(const Elem& e)
{
    ++n;
    S.addFront(e);
}

void LinkedStack::pop() throw(StackEmpty)
{
    if(empty()) throw StackEmpty("Pop of empty stack");
    --n;
    S.removeFront();
}