#include "Point2D.h"

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