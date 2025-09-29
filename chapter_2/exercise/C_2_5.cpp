#include <iostream>
#include <vector>

using namespace std;

class Progression{
    public:
        Progression() : first(2), second(200)
        {

        }

        Progression(int first, int second)
        {
            this->first = first;
            this->second = second;
        }

        string Caculate(int num)
        {
            for(int i = 0; i < num; i++)
            {
                if(i == 0)  cout << first << "\t";
                else if(i == 1)  cout << second << "\t";
                else
                {
                    int temp = second;
                    second -= first;
                    second = second < 0 ? -second : second;
                    first = temp;
                    cout << second << "\t";
                }
            }

            cout << endl;
        }
    private:
        int first;
        int second;
};

int main()
{
    Progression p;
    p.Caculate(10);

    Progression p1(2, 4);
    p1.Caculate(10);

    return EXIT_SUCCESS;
}