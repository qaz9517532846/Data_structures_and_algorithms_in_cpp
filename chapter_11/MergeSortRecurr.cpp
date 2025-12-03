#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename E, typename C>
void merge(const vector<E> &in, vector<E> &out, const C& less, int b, int m){
    int i = b;
    int j = b + m;
    int n = in.size();
    int e1 = min(b + m, n);
    int e2 = min(b + 2 * m, n);
    int k = b;
    while (i < e1 && j < e2) {
        if (!less(in[j], in[i]))
            out[k++] = in[i++];
        else
            out[k++] = in[j++];
    }
    while (i < e1)
        out[k++] = in[i++];
    while (j < e2)
        out[k++] = in[j++];
}

template <typename E, typename C>
void mergeSort(vector<E> &S, const C& less){
    typedef vector<E> vect;
    int n = S.size();
    vect v1(S); vect* in = &v1;
    vect v2(n); vect* out = &v2;
    for (int m = 1; m < n; m *= 2) {
        for (int b = 0; b < n; b += 2 * m) {
            merge(*in, *out, less, b, m);
        }
        swap(in, out);
    }
    S = *in;
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

    mergeSort(points, LeftRight());

    cout << "\nPoints sorted left to right:" << endl;
    for (const auto& p : points) {
        cout << p << " ";
    }

    return 0;
}