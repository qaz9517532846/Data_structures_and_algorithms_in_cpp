#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename E, typename C>
void quickSortStep(vector<E>& S, int a, int b, const C& less)
{
    if (a >= b) return; // subarray is already sorted
    E pivot = S[b]; // choose pivot
    int l = a;
    int r = b - 1;
    while (l <= r) {
        while (l <= r && !less(pivot, S[l])) l++;
        while (r >= l && !less(S[r], pivot)) r--;
        if (l < r)
            swap(S[l], S[r]);
    }
    swap(S[l], S[b]); // place pivot in final position
    quickSortStep(S, a, l - 1, less); // sort left subarray
    quickSortStep(S, l + 1, b, less); // sort right subarray
}

template <typename E, typename C>
void quickSort(vector<E>& S, const C& less)
{
    if (S.size() <= 1) return; // array is already sorted
    quickSortStep(S, 0, S.size() - 1, less);
}

class LeftRight {
    public:
        bool operator()(const int& p, const int& q) const {
            return p < q;
        }
};

int main()
{
    vector<int> points = { 3, 1, 5, 2 , 4};
    
    cout << "Original points:" << endl;
    for (const auto& p : points) {
        cout << p << " ";
    }

    quickSort(points, LeftRight());

    cout << "\nPoints sorted left to right:" << endl;
    for (const auto& p : points) {
        cout << p << " ";
    }

    return 0;
}