#include <iostream>
#include <vector>

using namespace std;

class Vector2
{
    public:
        Vector2(double x, double y)
        {
            this->x = x;
            this->y = y;
        }

        ~Vector2()
        {

        }

        Vector2 operator+(const Vector2& other)
        {
            return Vector2(x + other.x, y + other.y);
        }

        Vector2 operator*(double scale)
        {
            return Vector2(x * scale, y * scale);
        }

        double operator*(const Vector2& other)
        {
            return x * other.x + y * other.y;
        }

        double x;
        double y;
};

int main()
{
    Vector2 v1(1.0, 2.0);
    Vector2 v2(3.0, 4.0);

    Vector2 sum = v1 + v2;
    Vector2 scaled = v1 * 2.0;
    double dot = v1 * v2;

    cout << "v1 + v2 = " << "( " << sum.x << ", " << sum.y << " )" << endl;
    cout << "v1 * 2.0 = " << "( " << scaled.x << ", " << scaled.y << " )" << endl;
    cout << "v1 dot v2 = " << dot << endl;
    
    return EXIT_SUCCESS;
}