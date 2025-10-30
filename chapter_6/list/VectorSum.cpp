#include <iostream>
#include <vector>

using namespace std;

int vectorSum1(const vector<int>& V)
{
    int sum = 0;
    for (size_t i = 0; i < V.size(); ++i) {
        sum += V[i];
    }
    return sum;
}

int vectorSum2(vector<int> V)
{
    typedef vector<int>::iterator Iterator;
    int sum = 0;
    for (Iterator p = V.begin(); p != V.end(); ++p) {
        sum += *p;
    }
    return sum;
}

int vectorSum3(const vector<int>& V)
{
    typedef vector<int>::const_iterator ConstIterator;
    int sum = 0;
    for (ConstIterator p = V.begin(); p != V.end(); ++p) {
        sum += *p;
    }
    return sum;
}

int main()
{
    vector<int> V = {1, 2, 3, 4, 5};

    cout << "Sum using index-based loop: " << vectorSum1(V) << endl;
    cout << "Sum using iterator-based loop: " << vectorSum2(V) << endl;
    cout << "Sum using const iterator-based loop: " << vectorSum3(V) << endl;

    return 0;
}