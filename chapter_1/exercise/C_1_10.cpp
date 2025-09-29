#include <iostream>
#include <vector>

using namespace std;

long PowerOfTwo(int i)
{
    return 1L << i;
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        cout << PowerOfTwo(i) << endl;
    }

    return EXIT_SUCCESS;
}