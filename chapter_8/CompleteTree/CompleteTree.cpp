#include "../CompleteTree.h"

int main() {
    VectorCompleteTree<Elem> T;
    T.addLast(10);
    T.addLast(20);
    T.addLast(30);
    T.addLast(40);
    T.addLast(50);

    VectorCompleteTree<Elem>::Position r = T.root();
    cout << "Root: " << *r << endl;

    if (T.hasLeft(r)) {
        VectorCompleteTree<Elem>::Position l = T.left(r);
        cout << "Left child of root: " << *l << endl;
    }

    if (T.hasRight(r)) {
        VectorCompleteTree<Elem>::Position rt = T.right(r);
        cout << "Right child of root: " << *rt << endl;
    }

    VectorCompleteTree<Elem>::Position last = T.last();
    cout << "Last element: " << *last << endl;

    T.swap(r, last);
    cout << "After swapping root and last element:" << endl;
    cout << "New Root: " << *T.root() << endl;
    cout << "New Last element: " << *T.last() << endl;

    return 0;
}