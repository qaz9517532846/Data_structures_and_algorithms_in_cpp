#include <iostream>

using namespace std;

int Fibonacci(int k)
{
    if(k <= 1)
        return k;
    else
        return Fibonacci(k- 1) + Fibonacci(k - 2);
}

int main()
{
    cout << Fibonacci(1) << endl;
    cout << Fibonacci(2) << endl;
    cout << Fibonacci(3) << endl;
    cout << Fibonacci(4) << endl;
    cout << Fibonacci(5) << endl;
    cout << Fibonacci(6) << endl;
    return EXIT_SUCCESS;
}