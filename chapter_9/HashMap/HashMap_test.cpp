#include "../HashMap.h"
#include "../NonexistentElement.h"

// ============================================================
// Test Functions
// ============================================================

void testHashMapString() {
    cout << "\n=== Testing HashMap with String Keys ===" << endl;
    
    HashMap<string, int, HashString> map(10);
    
    // Insert elements
    map.put("Alice", 25);
    map.put("Bob", 30);
    map.put("Charlie", 35);
    map.put("Diana", 28);
    
    cout << "Size after insertions: " << map.size() << endl;
    
    // Find elements
    cout << "\nFinding elements:" << endl;
    auto it = map.find("Alice");
    if (it != map.end()) {
        cout << "Found: " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    it = map.find("Bob");
    if (it != map.end()) {
        cout << "Found: " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Update element
    map.put("Alice", 26);
    it = map.find("Alice");
    if (it != map.end()) {
        cout << "Updated: " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Iterate through all elements
    cout << "\nAll elements:" << endl;
    for (auto it = map.begin(); it != map.end(); ++it) {
        cout << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Erase element
    map.erase("Bob");
    cout << "\nSize after erasing Bob: " << map.size() << endl;
    
    // Try to find erased element
    it = map.find("Bob");
    if (it == map.end()) {
        cout << "Bob not found (correctly erased)" << endl;
    }
}

void testHashMapInt() {
    cout << "\n=== Testing HashMap with Integer Keys ===" << endl;
    
    HashMap<int, string, HashInt> map(10);
    
    // Insert elements
    map.put(1, "One");
    map.put(2, "Two");
    map.put(3, "Three");
    map.put(11, "Eleven"); // Will hash to same bucket as 1
    map.put(21, "Twenty-one"); // Will hash to same bucket as 1
    
    cout << "Size: " << map.size() << endl;
    
    // Find elements
    cout << "\nFinding elements:" << endl;
    auto it = map.find(1);
    if (it != map.end()) {
        cout << "Found: " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    it = map.find(11);
    if (it != map.end()) {
        cout << "Found: " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    it = map.find(21);
    if (it != map.end()) {
        cout << "Found: " << (*it).key() << " -> " << (*it).value() << endl;
    }
    
    // Iterate through all elements
    cout << "\nAll elements:" << endl;
    for (auto it = map.begin(); it != map.end(); ++it) {
        cout << (*it).key() << " -> " << (*it).value() << endl;
    }
}

void testHashMapCollisions() {
    cout << "\n=== Testing HashMap Collision Handling ===" << endl;
    
    HashMap<int, string, HashInt> map(5); // Small capacity to force collisions
    
    // Insert elements that will collide
    map.put(0, "Zero");
    map.put(5, "Five");    // Same bucket as 0
    map.put(10, "Ten");    // Same bucket as 0
    map.put(1, "One");
    map.put(6, "Six");     // Same bucket as 1
    
    cout << "Size: " << map.size() << endl;
    
    // Verify all elements can be found
    cout << "\nVerifying all elements:" << endl;
    for (int key : {0, 5, 10, 1, 6}) {
        auto it = map.find(key);
        if (it != map.end()) {
            cout << "Found: " << (*it).key() << " -> " << (*it).value() << endl;
        } else {
            cout << "ERROR: Could not find key " << key << endl;
        }
    }
}

void testHashMapException() {
    cout << "\n=== Testing HashMap Exception Handling ===" << endl;
    
    HashMap<string, int, HashString> map(10);
    
    map.put("Test", 100);
    
    try {
        map.erase("NonExistent");
        cout << "ERROR: Should have thrown exception!" << endl;
    } catch (const NonexistentElement& e) {
        cout << "Caught exception correctly: " << e.getMessage() << endl;
    }
}

int main() {
    cout << "==================================================" << endl;
    cout << "    Chapter 9: HashMap (Hash Tables)" << endl;
    cout << "==================================================" << endl;
    
    testHashMapString();
    testHashMapInt();
    testHashMapCollisions();
    testHashMapException();
    
    return 0;
}