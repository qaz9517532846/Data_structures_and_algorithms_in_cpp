#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if(a + b == c)
        cout << a << " + " << b << " = " << c << endl;
    else if(a == b - c)
        cout << a << " = " << b << " - " << c << endl;
    else if(a * b == c)
        cout << a << " x " << b << " = " << c << endl;
    else
        std::cout << "No valid arithmetic relation found." << std::endl;
    
    return EXIT_SUCCESS;
}