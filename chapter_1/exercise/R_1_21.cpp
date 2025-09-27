#include <iostream>
#include <cmath>

using namespace std;

int sum(int n)
{
    int result = 0;

    for(int i = 1; i <= n; i += 2)
    {
        result += i;
    }

    if(n < 1) result = 0;

    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << "sum = " << sum(n) << endl;

    return EXIT_SUCCESS;
}