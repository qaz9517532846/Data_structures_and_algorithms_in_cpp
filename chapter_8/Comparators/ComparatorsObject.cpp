#include <iostream>
#include <vector>
#include "../Point2D.h"

using namespace std;

class LeftRight {
    public:
        bool operator()(const Point2D& p, const Point2D& q) const {
            return p.getX() < q.getX();
        }
};

class BottomTop {
    public:
        bool operator()(const Point2D& p, const Point2D& q) const {
            return p.getY() < q.getY();
        }
};

template <typename E, typename C>
void printSmaller(const E& p, const E& q, const C& isLess) {
    if(isLess(p, q))
        cout << "Smaller point is: (" << p.getX() << ", " << p.getY() << ")" << endl;
    else
        cout << "Smaller point is: (" << q.getX() << ", " << q.getY() << ")" << endl;
}

int main() {
    Point2D p(1.3, 5.7), q(2.5, 0.6);
    LeftRight leftRight;
    BottomTop bottomTop;
    printSmaller(p, q, leftRight);
    printSmaller(p, q, bottomTop);

    return EXIT_SUCCESS;
}