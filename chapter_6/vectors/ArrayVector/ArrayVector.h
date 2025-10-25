#ifndef ARRAYVECTOR_H
#define ARRAYVECTOR_H

#include "../VectorException.h"

typedef int Elem;
class ArrayVector {
    public:
        ArrayVector();
        int size() const;
        bool empty() const;
        Elem& operator[](int i);
        Elem& at(int i) throw(IndexOutOfBounds);
        void erase(int i);
        void insert(int i, const Elem& ele);
        void reserve(int N);


    private:
        int capacity;
        int n;
        Elem* A;

};

#endif