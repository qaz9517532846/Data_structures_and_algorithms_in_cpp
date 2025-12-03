#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename E, typename C>
void merge(const list<E> &S1, const list<E> &S2, list<E> &S, const C& less)
{
    typedef typename list<E>::const_iterator Itor;
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    while (p1 != S1.end() && p2 != S2.end()) {
        if (less(*p1, *p2))
            S.push_back(*p1++);
        else
            S.push_back(*p2++);
    }
    while (p1 != S1.end())
        S.push_back(*p1++);
    while (p2 != S2.end())
        S.push_back(*p2++);
}

template <typename E, typename C>
void mergeSort(list<E> &S, const C& less)
{
    typedef typename list<E>::iterator Itor;
    int n = S.size();
    if (n <= 1) return; // list is already sorted
    list<E> S1, S2;
    Itor p = S.begin();
    for (int i = 0; i < n / 2; ++i) S1.push_back(*p++);
    for (int i = n / 2; i < n; ++i) S2.push_back(*p++);
    S.clear();
    mergeSort(S1, less);
    mergeSort(S2, less);
    merge(S1, S2, S, less);
}

class LeftRight {
    public:
        bool operator()(const int& p, const int& q) const {
            return p < q;
        }
};

int main()
{
    list<int> points = { 3, 1, 5, 2 , 4};
    
    cout << "Original points:" << endl;
    for (const auto& p : points) {
        cout << p << " ";
    }

    mergeSort(points, LeftRight());

    cout << "\nPoints sorted left to right:" << endl;
    for (const auto& p : points) {
        cout << p << " ";
    }

    return 0;
}