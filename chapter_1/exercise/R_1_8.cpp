#include <iostream>
#include <cmath>

using namespace std;

bool isMultiple(long m, long n)
{
    return n % m == 0;
}

int main()
{
    long m, n;

    cin >> m >> n;

    bool result = isMultiple(m, n);

    cout << result << endl;

    return EXIT_SUCCESS;
}