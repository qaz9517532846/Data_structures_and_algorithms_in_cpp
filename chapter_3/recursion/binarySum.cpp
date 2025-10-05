#include <iostream>

using namespace std;

int BinarySum(int a[], int i, int n)
{
    if(n == 1)
        return a[i];
    else
        return BinarySum(a, i, n / 2) + BinarySum(a, i + n / 2, n / 2);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << BinarySum(arr, 0, 8) << endl;
    return EXIT_SUCCESS;
}