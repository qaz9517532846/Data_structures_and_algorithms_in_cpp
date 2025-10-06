#include <iostream>

using namespace std;

void StringReverse(string &data, int pos)
{
    if(pos > data.size() / 2)   return;
    else
    {
        char temp = data[pos];
        data[pos] = data[data.size() - 1 - pos];
        data[data.size() - 1 - pos] = temp;

        return StringReverse(data, pos + 1);
    }
}

int main()
{
    string s = "pots&pans";

    StringReverse(s, 0);

    cout << "Reverse : " << s << endl;

    return EXIT_SUCCESS;
}