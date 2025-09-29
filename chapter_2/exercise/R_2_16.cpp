#include <iostream>
#include <vector>

using namespace std;

string RemovePunctuation(string message)
{
    int pos = message.find("'");
    message.erase(pos, 1);

    pos = message.find(",");
    message.erase(pos, 1);

    return message;
}

int main()
{
    string msg = "Let's try, Mike";

    cout << RemovePunctuation(msg) << endl;

    return EXIT_SUCCESS;
}