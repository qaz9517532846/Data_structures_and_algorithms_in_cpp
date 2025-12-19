#include "../HashDict.h"

void testHashDict() {
    cout << "\n=== Testing HashDict (Multimap) ===" << endl;
    
    HashDict<string, int, HashString> dict(10);
    
    // Insert multiple values with the same key
    cout << "\nInserting multiple values with same keys:" << endl;
    dict.insert("student", 100);
    dict.insert("student", 101);
    dict.insert("student", 102);
    dict.insert("teacher", 200);
    dict.insert("teacher", 201);
    dict.insert("admin", 300);
    
    cout << "Total entries: " << dict.size() << endl;
    
    // Iterate through all entries first to verify
    cout << "\nAll entries in HashDict:" << endl;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        cout << "  " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Find all entries with key "student"
    cout << "\nFinding all entries with key 'student':" << endl;
    auto range1 = dict.findAll("student");
    for (auto it = range1.begin(); it != range1.end(); ++it) {
        cout << "  " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Find all entries with key "teacher"
    cout << "\nFinding all entries with key 'teacher':" << endl;
    auto range2 = dict.findAll("teacher");
    for (auto it = range2.begin(); it != range2.end(); ++it) {
        cout << "  " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Find all entries with key "admin"
    cout << "\nFinding all entries with key 'admin':" << endl;
    auto range3 = dict.findAll("admin");
    for (auto it = range3.begin(); it != range3.end(); ++it) {
        cout << "  " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Test with non-existent key
    cout << "\nFinding all entries with key 'nonexistent':" << endl;
    auto range4 = dict.findAll("nonexistent");
    bool found = false;
    for (auto it = range4.begin(); it != range4.end(); ++it) {
        cout << "  " << (*it).key() << " -> " << (*it).value() << endl;
        found = true;
    }
    if (!found) {
        cout << "  (No entries found - correct)" << endl;
    }
    
    cout << "\nHashDict test completed!" << endl;
}

int main() {
    cout << "==================================================" << endl;
    cout << "    Chapter 9: HashDict (Hash Tables)" << endl;
    cout << "==================================================" << endl;
    
    // Test HashDict (multimap)
    testHashDict();
    
    return 0;
}