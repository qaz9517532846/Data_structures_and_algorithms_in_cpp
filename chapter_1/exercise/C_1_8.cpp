#include <iostream>
#include <vector>

using namespace std;

vector<double> ElementProduct(vector<double> a, vector<double> b)
{
    vector<double> result;

    result.resize(a.size());

    for(int i = 0; i < a.size(); i++)
    {
        result[i] = a[i] * b[i];
    }

    return result; 
}

int main()
{
    vector<double> a = {1.0, 2.0, 3.0};
    vector<double> b = {4.0, 5.0, 6.0};

    vector<double> c = ElementProduct(a, b);

    for(int i = 0; i < c.size(); i++)
    {
        cout << c[i] << "\t";
    }

    return EXIT_SUCCESS;
}