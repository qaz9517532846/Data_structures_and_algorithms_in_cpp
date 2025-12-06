#include "Mergable.h"

template <typename E>
void Merge<E>::merge(List& A, List& B, List& C)
{
    Itor pa = A.begin();
    Itor pb = B.begin();

    while (pa != A.end() && pb != B.end()) {
        if (*pa < *pb) {
            fromA(*pa++, C);
        } else if (*pb == *pa) {
            fromBoth(*pa++, *pb++, C);
        } else {
            fromB(*pb++, C);
        }
    }

    while (pa != A.end()) { fromA(*pa++, C); }
    while (pb != B.end()) { fromB(*pb++, C); }
}

int main()
{
    typedef Merge<int>::List List;

    List A = {1, 2, 2, 4, 6, 7, 9};
    List B = {2, 2, 3, 5, 6, 8, 10};

    List C;

    UnionMerge<int> um;
    um.merge(A, B, C);

    std::cout << "Union: ";
    for (auto e : C) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    C.clear();
    IntersectionMerge<int> im;
    im.merge(A, B, C);

    std::cout << "Intersection: ";
    for (auto e : C) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    C.clear();
    SubtractionMerge<int> sm;
    sm.merge(A, B, C);

    std::cout << "Subtraction (A - B): ";
    for (auto e : C) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}