#include <iostream>
#include <vector>

using namespace std;

class ZeroDivide{
    public:
        ZeroDivide(string msg)
        {
            err = msg;
        }

        string GetError()
        {
            return err;
        }
    private:
        string err;
};

void intersect(double a, double b)
{
    int x = 0;

    try
    {
        if(a == 0) throw ZeroDivide("Divide by zero in Module X");
        x = - b / a;
    }
    catch(ZeroDivide &e)
    {
        std::cerr << e.GetError() << '\n';
    }
    
}

int main()
{
    int a = 1, b = 3;

    cout << "a = " << a << " , " << "b = " << b << endl;
    intersect(a, b);

    a = 0, b = 3;
    cout << "a = " << a << " , " << "b = " << b << endl;
    intersect(a, b);

    return EXIT_SUCCESS;
}