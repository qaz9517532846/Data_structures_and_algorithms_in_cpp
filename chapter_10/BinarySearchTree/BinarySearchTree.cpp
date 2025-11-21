#include <iostream>
#include <cstdlib>
#include "../SearchTree.h"

int main() {
    SearchTree<Entry<int, std::string>> st;
    st.insert(5, "five");
    st.insert(3, "three");
    st.insert(7, "seven");

        // --- debugging prints ---
    std::cout << "Search size: " << st.size() << std::endl;
    auto b = st.begin();
    auto e = st.end();
    std::cout << "begin() == end()? " << (b == e ? "yes" : "no") << std::endl;
    if (b != e) {
        std::cout << "Iterating contents:" << std::endl;
        for (auto it = b; it != e; ++it) {
            std::cout << "Key: " << (*it).key() << ", Value: " << (*it).value() << std::endl;
        }
    } else {
        std::cout << "Iterator is empty (begin==end). Insertion may have failed or iterator logic is wrong." << std::endl;
    }

    auto itf = st.find(3);
    if (itf != st.end()) {
        std::cout << "find(3) -> key=" << (*itf).key() << " value=" << (*itf).value() << std::endl;
    } else {
        std::cout << "key 3 not found\n";
    }

    std::cout << "Finished." << std::endl;
    
    return EXIT_SUCCESS;
}