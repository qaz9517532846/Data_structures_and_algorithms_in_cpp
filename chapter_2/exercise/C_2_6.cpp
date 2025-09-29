#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Progression{
    public:
        Progression() : first(65536)
        {

        }

        Progression(double first)
        {
            this->first = first;
        }

        string Caculate(double num)
        {
            for(int i = 0; i < num; i++)
            {
                if(i == 0)  cout << first << "\t";
                else
                {
                    first = sqrt(first);
                    cout << first << "\t";
                }
            }

            cout << endl;
        }
    private:
        double first;
};

int main()
{
    Progression p;
    p.Caculate(10);

    Progression p1(1024);
    p1.Caculate(10);

    return EXIT_SUCCESS;
}