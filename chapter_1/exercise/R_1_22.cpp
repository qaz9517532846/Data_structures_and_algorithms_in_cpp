#include <iostream>
#include <cmath>

using namespace std;

int divideNumber(double x)
{
    int cnt = 0;

    while(x >= 2.0)
    {
        x = x / 2.0;
        cnt++;
    }

    return cnt;
}

int main()
{
    int x;
    cin >> x;
    cout << "divide 2 number of times = " << divideNumber(x) << endl;

    return EXIT_SUCCESS;
}