#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int w = 0, y = 1, z = 2;

    int result1 = y + 2 * z++;
    int result2 = 3 - w / 5;

    bool result = result1 < result2;

    cout << result1 << " < " << result2 << "==>" << result << endl;

    return EXIT_SUCCESS;
}
