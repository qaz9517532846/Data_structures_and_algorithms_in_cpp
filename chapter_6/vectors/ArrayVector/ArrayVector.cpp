#include <iostream>
#include "ArrayVector.h"


using namespace std;

ArrayVector::ArrayVector() : capacity(0), n(0), A(NULL)
{

}

int ArrayVector::size() const {
    return n;
}

bool ArrayVector::empty() const {
    return size() == 0;
}

Elem& ArrayVector::operator[](int i) {
    return A[i];
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
    if(i < 0 || i >= n)
        throw IndexOutOfBounds("illegal indexin function at()");
    return A[i];
}

void ArrayVector::erase(int i) {
    if(i < 0 || i >= n)
        throw IndexOutOfBounds("illegal indexin function erase()");
    for(int j = i + 1; j < n; j++) {
        A[j - 1] = A[j];
    }
    n--;
}

void ArrayVector::reserve(int N) {
    if (capacity >= N) return;
    Elem* B = new Elem[N];
    for (int j = 0; j < n; j++)
        B[j] = A[j];
    if (A != NULL) delete [ ] A;
    A = B;
    capacity = N;
}

void ArrayVector::insert(int i, const Elem& e)
{
    if (n >= capacity)
        reserve(max(1, 2 *capacity));

    for (int j = n - 1; j >= i; j--)
        A[j+1] = A[j];
    A[i] = e;
    n++;
}

int main()
{
    ArrayVector array;
    array.insert(0, 0);
    array.insert(1, 1);
    array.insert(2, 2);
    array.insert(3, 3);
    cout << "A[0] : " << array[0] << endl;
    cout << "A[1] : " << array.at(1) << endl;
    array.erase(1);
    cout << "A[1] : " << array.at(1) << endl;
    return 0;
}