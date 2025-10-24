#include "LinkedStack.h"

int main()
{
    LinkedStack A;
    A.push("Bob");
    A.push("Alice");
    cout << A.top() << endl;
    A.pop();
    A.push("Eve");
    cout << A.top() << endl;
    return 0;
}