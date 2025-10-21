#include <iostream>
#include <vector>
#include "ArrayStack.h"

using namespace std;

template<typename E>
void reverse(vector<E>& V)
{
    ArrayStack<E> S(V.size());
    for(int i = 0 ; i < V.size() ; ++i)
        S.push(V[i]);
    
    for(int i = 0 ; i < V.size() ; ++i)
    {
        V[i] = S.top();
        S.pop();
    }
}

int main(void) {
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout << A.top() << endl;
    A.pop();
    A.push(9);
    cout << A.top() << endl;
    cout << A.top() << endl;
    A.pop();

    ArrayStack<string> B(10);
    B.push("Bob");
    B.push("Alice");
    cout << B.top() << endl;
    B.pop();
    B.push("Eve");
    return 0;
}
