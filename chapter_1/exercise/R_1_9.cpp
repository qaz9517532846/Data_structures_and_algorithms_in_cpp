#include <iostream>

using namespace std;

void printArray(int** a, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }

        cout << endl;
    }
}

int main()
{
    int m = 3, n = 4;

    // Dynamically allocate a 2D array
    int** A = new int*[m];

    for (int i = 0; i < m; ++i)
    {
        A[i] = new int[n];
    }

    // Initialize the array
    int counter = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = counter++;
        }
    }

    // Call the print function
    printArray(A, m, n);

    // Free the allocated memory
    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return EXIT_SUCCESS;
}