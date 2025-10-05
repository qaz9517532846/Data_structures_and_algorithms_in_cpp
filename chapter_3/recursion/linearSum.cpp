#include <iostream>

using namespace std;

int LinearSum(int a[], int n)
{
    if(n == 1)
        return a[0];
    else
        return LinearSum(a, n - 1) + a[n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << LinearSum(arr, 9) << endl;
    return EXIT_SUCCESS;
}