#include <iostream>
#include <vector>

using namespace std;

void Rearrange(vector<int> &data, int pos, int cnt)
{
    if(cnt == data.size())  return;
    else
    {
        if(data[pos] % 2 == 1)
        {
            data.push_back(data[pos]);
            data.erase(data.begin() + pos);
        }
        else
            pos++;

        return Rearrange(data, pos, cnt + 1);
    }
}

int main()
{
    vector<int> array = {1, 6, 5, 9, 11, 18, 16, 17, 30, 48, 68};
    Rearrange(array, 0, 0);

    cout << "Rearrange result : ";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}