#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Dummy puzzle test – modify to your own condition
bool is_solution(const vector<int>& S) {
    // Example: return true if sum is 6
    int sum = 0;
    for (int x : S) sum += x;
    return sum == 6;
}

void PuzzleSolve(int k, vector<int>& S, set<int> U) {
    for (int e : U) {
        vector<int> S_copy = S;
        set<int> U_copy = U;

        S_copy.push_back(e);
        U_copy.erase(e);

        if (k == 1) {
            if (is_solution(S_copy)) {
                cout << "Solution found: ";
                for (int x : S_copy)
                    cout << x << " ";
                cout << endl;
            }
        } else {
            PuzzleSolve(k - 1, S_copy, U_copy);
        }
    }
}

int main() {
    vector<int> S;
    set<int> U = {1, 2, 3};  // Elements to use
    int k = 3; // Length of desired sequence

    PuzzleSolve(k, S, U);

    return 0;
}
