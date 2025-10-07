#include <iostream>

using namespace std;

bool IsPalindromes(string &data, int pos)
{
    bool result = true;
    int length = data.size();

    if(pos > length / 2)                            return true;
    else
    {
        if(data[pos] == data[length - pos - 1])     return IsPalindromes(data, pos + 1);
        else                                        return false;
    }
}

int main()
{
    string s = "gohangasalamiimalasagnahog";

    cout << "Is Reverse : " << (IsPalindromes(s, 0) ? "TRUE" : "FALSE") << endl;

    return EXIT_SUCCESS;
}