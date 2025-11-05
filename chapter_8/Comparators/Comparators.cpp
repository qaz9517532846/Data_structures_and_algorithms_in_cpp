#include <iostream>
#include <vector>
#include "../Point2D.h"

using namespace std;

bool operator<(const Point2D& p, const Point2D& q) {
    if(p.getX() != q.getX())    return p.getX() < q.getX();
    else                        return p.getY() < q.getY();
}

int main() {
    Point2D a(1.0, 2.0);
    Point2D b(2.0, 1.0);

    if(a < b) {
        cout << "Point a is less than Point b" << endl;
    } else {
        cout << "Point a is not less than Point b" << endl;
    }
    
    return EXIT_SUCCESS;
}