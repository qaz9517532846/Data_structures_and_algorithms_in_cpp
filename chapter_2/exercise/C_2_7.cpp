#include <iostream>

using namespace std;

class A
{
    public:
        int x;
        A() : x(0)
        {

        }
};

class B : public A
{
    public:
        int x;
        B() : x(0)
        {
            
        }
};

class C : public B
{
    public:
        int x;
        C() : x(0)
        {

        }

        void SetA_X(int x)
        {
            A::x = x; 
        }

        void ShowAllX()
        {
            cout << "A::x = " << A::x << endl;
            cout << "B::x = " << B::x << endl;
            cout << "C::x = " << x << endl;  // C's x
        }
};

int main()
{
    C obj;

    obj.x = 30;         // Sets C's x
    obj.B::x = 20;      // Sets B's x
    obj.SetA_X(10);     // Sets A's x using C's member function

    obj.ShowAllX();     // Display all x values

    return EXIT_SUCCESS;
}