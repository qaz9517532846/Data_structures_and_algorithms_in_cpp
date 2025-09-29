#include <iostream>
#include <vector>

using namespace std;

int CaculateVowelsNum(string character)
{
    int num = 0;

    for(int i = 0; i < character.size(); i++)
    {
        if(character[i] == 'a' || 
           character[i] == 'e' ||
           character[i] == 'i' ||
           character[i] == 'o' ||
           character[i] == 'u')
        {
            num++;
        }
    }

    return num;
}

int main()
{
    string msg = "Hello, World!";

    cout << CaculateVowelsNum(msg) << endl;

    return EXIT_SUCCESS;
}