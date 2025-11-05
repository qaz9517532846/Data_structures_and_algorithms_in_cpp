class Point2D {
    public:
        Point2D(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

        double getX() const { return x_; }
        double getY() const { return y_; }

        void setX(double x) { x_ = x; }
        void setY(double y) { y_ = y; }
    private:
        double x_;
        double y_;
};