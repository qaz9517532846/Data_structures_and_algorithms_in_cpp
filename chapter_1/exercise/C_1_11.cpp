#include <iostream>
#include <vector>

using namespace std;

int FindGCD(int a, int b)
{
    while(b != 0)
    {
        int temp;
        temp = b;
        b = a % b;
        a = temp;
    }

    return (a < 0) ? -a : a;
}

int main()
{
    cout << "result = " << FindGCD(80844, 25320) << endl;

    return EXIT_SUCCESS;
}