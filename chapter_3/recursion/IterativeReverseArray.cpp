#include <iostream>

using namespace std;

void InterativeReverseArray(int arr[],int i, int j);

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof arr / sizeof arr[0];
    int i = 0;
    int j = n - 1;
    InterativeReverseArray(arr, i, j);
    for (int i : arr)
        cout << i << "\t";
    return 0;
}

void InterativeReverseArray(int arr[], int i, int j) {
    while(i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i = i + 1;
        j = j - 1;
    }
    return;
}
