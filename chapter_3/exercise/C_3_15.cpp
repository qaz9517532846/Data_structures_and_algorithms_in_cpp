#include <iostream>
#include <vector>

using namespace std;

void GenerateSubsets(vector<int> &set, vector<int> &subset, int idx)
{
    if(idx == set.size()) {
        cout << "{";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    GenerateSubsets(set, subset, idx + 1);
    subset.push_back(set[idx]);
    GenerateSubsets(set, subset, idx + 1);
    subset.pop_back();
}

int main()
{
    vector<int> set = {1, 3, 5, 7, 9, 11};
    vector<int> subset;
    cout << "All subsets are:" << endl;
    GenerateSubsets(set, subset, 0);

    return EXIT_SUCCESS;
}