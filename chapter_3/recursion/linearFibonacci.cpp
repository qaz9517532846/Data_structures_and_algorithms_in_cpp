#include <iostream>
#include <vector>

using namespace std;

pair<int, int> LinearFibonacci(int k)
{
    if(k == 0)  return {0, 0};
    if(k == 1)  return {1, 0};

    auto prev = LinearFibonacci(k - 1);
    int fk = prev.first + prev.second;

    return {fk, prev.first};
}

int main()
{
    int k = 10;
    auto result = LinearFibonacci(k);
    cout << "F(" << k << ") = " << result.first << ", F(" << k - 1 << ") = " << result.second << endl;
    return EXIT_SUCCESS;
}