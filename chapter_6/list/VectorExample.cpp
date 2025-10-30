#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {17, 12, 33, 15, 62, 45};
    vector<int> v(a, a + 6);
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;
    v.push_back(19);
    cout << v.front() << " " << v.back() << endl;
    sort(v.begin(), v.begin() + 4);
    v.erase(v.end() - 4, v.end() - 2);
    cout << v.size() << endl;

    char b[] = {'b', 'r', 'a', 'v', 'o'};
    vector<char> w(b, b + 5);
    random_shuffle(w.begin(), w.end());
    w.insert(w.begin(), 's');

    for(vector<char>::iterator p = w.begin(); p != w.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}