#include <iostream>
#include <vector>
#include <queue>
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

int main() {
    priority_queue<Point2D, vector<Point2D>, LeftRight> p2;
    p2.push( Point2D(8.5, 4.6) );
    // add three points to p2
    p2.push( Point2D(1.3, 5.7) );
    p2.push( Point2D(2.5, 0.6) );
    cout << "(" << p2.top().getX() << " ," << p2.top().getY() << ")" << endl;
    p2.pop(); // output: (8.5, 4.6)
    cout << "(" << p2.top().getX() << " ," << p2.top().getY() << ")" << endl;
    p2.pop(); // output: (2.5, 0.6)
    cout << "(" << p2.top().getX() << " ," << p2.top().getY() << ")" << endl;
    p2.pop(); // output: (1.3, 5.7)

    return EXIT_SUCCESS;
}