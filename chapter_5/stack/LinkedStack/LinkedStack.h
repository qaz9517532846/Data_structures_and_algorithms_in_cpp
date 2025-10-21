#include <iostream>
#include <vector>
#include "../stackEmptyException.h"
#include "SLinkedList.h"

using namespace std;

typedef string Elem;
class LinkedStack {
    public:
        LinkedStack();
        int size() const;
        bool empty() const;
        const Elem& top() const throw(StackEmpty);
        void push(const Elem& e);
        void pop() throw(StackEmpty);
    private:
        SLinkedList<Elem> S;
        int n;
};