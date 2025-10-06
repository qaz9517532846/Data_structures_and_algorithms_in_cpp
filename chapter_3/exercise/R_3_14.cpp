#include <iostream>
#include <vector>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()

using namespace std;

int random(int k)
{
    return rand() % (k + 1);
}

void RemoveRandomEntries(vector<int> arr)
{
    if(arr.empty())     return;
    else
    {
        int idx = random(arr.size() - 1);
        cout << "Remove idx = " << idx << endl;
        arr.erase(arr.begin() + idx);
        RemoveRandomEntries(arr);
    }
}

int main()
{
    srand(time(0));

    std::vector<int> arr = {10, 20, 30, 40, 50};
    RemoveRandomEntries(arr);

    return EXIT_SUCCESS;
}