#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s = "abc";
    string t = "cde";
    s += s + t[1] + s;

    cout << s << endl;

    return EXIT_SUCCESS;
}