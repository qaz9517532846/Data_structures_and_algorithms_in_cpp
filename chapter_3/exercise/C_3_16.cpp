#include <iostream>
#include <vector>

using namespace std;

int FindMinmum(vector<int> data)
{
    if(data.size() <= 1) return data[0];
    else
    {
        if(data[0] > data[1])   data.erase(data.begin());
        else                    data.erase(data.begin() + 1);
        
        return FindMinmum(data);
    }
}

int FindMaxmum(vector<int> data)
{
    if(data.size() <= 1) return data[0];
    else
    {
        if(data[0] < data[1])   data.erase(data.begin());
        else                    data.erase(data.begin() + 1);
        
        return FindMaxmum(data);
    }
}

int main()
{
    vector<int> array = {1, 11, 7, 9, 5, 3};

    cout << "Find Min : " <<  FindMinmum(array) << endl;
    cout << "Find Max : " <<  FindMaxmum(array) << endl;

    return EXIT_SUCCESS;
}