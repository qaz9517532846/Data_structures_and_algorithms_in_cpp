#include <iostream>
#include "DLinkedList.h"

using namespace std;

void listReverse(DLinkedList& L) {
    DLinkedList T;
    while(!L.empty()) {
        string s = L.front();
        L.removeFront();
        T.addFront(s);
    }

    while(!T.empty()) {
        string s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}

int main(void) {
    // Initialize a DLinkedList object
    DLinkedList list;

    // Is list empty? Yes, cause none of the elements have been inserted yet
    cout << "Is the list empty: "<< (list.empty() ? "True" : "False") << endl;

    //Add Elements at front and back
    list.addFront("Afrid Hussain");
    list.addBack("Bhavana");

    //listReverse(list);

    // Print Front and back elements in the list
    cout << list.front() << endl;
    cout << list.back() << endl;

    // Print all the elements
    list.printList();

    // Print all the elements in reverse order
    list.rprintList();

    // Check if the list is empty now
    cout << "Is the list empty: "<< (list.empty() ? "True" : "False") << endl;

    // Remove elements at front
    list.removeFront();

    // Remove elements at back
    list.removeBack();

    // Print list
    list.printList();

    // Check if the list is empty now
    cout << "Is the list empty: "<< (list.empty() ? "True" : "False") << endl;

    return 0;
}

