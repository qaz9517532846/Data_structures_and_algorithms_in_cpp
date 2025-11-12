#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<string, int> myMap;
    map<string, int>::iterator p;

    myMap.insert(make_pair<string, int>("Rob", 28));
    myMap["Joe"] = 38;
    myMap["Joe"] = 50;
    myMap["Sue"] = 75;
    p = myMap.find("Joe");
    myMap.erase(p);
    myMap.erase("Sue");
    p = myMap.find("Joe");
    if (p == myMap.end()) cout << "nonexistent\n";
    for (p = myMap.begin(); p != myMap.end(); ++p) {
        cout << "(" << p->first << "," << p->second << ")\n";
    }
    
    return EXIT_SUCCESS;
}