#include <iostream>
#include "DLinkedList.h"

using namespace std;


DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while(!empty() ) removeFront();
    delete header;
    delete trailer;
}


bool DLinkedList::empty() const {
    return header->next == trailer;
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) {
    add(trailer, e);
}

void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() {
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(trailer->prev);
}

void DLinkedList::printList() const {
    DNode* temp = header->next;
    if (temp == NULL) {
        cout << "List is empty" << endl;
    }

    while(temp != trailer) {
        cout << temp->elem << endl;
        temp = temp->next;
    }
}

void DLinkedList::rprintList() const {
    DNode* temp = trailer->prev;

    if (temp == NULL) {
        cout << "List is empty" << endl;
    }

    while(temp != header) {
        cout << temp->elem << endl;
        temp = temp->prev;
    }
}
