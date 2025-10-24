#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H 

#include <iostream>
#include <vector>

using namespace std;

typedef string Ele;

class CNode {
    private:
        Ele ele;
        CNode* next;

    friend class CLinkedList;
};

class CLinkedList {
    public:
        CLinkedList()
        {
            cursor = NULL;
        }

        ~CLinkedList()
        {
            while(!empty()) {
                remove();
            }
        }

        bool empty() const
        {
            return cursor == NULL;
        }

        const Ele& front() const
        {
            return cursor -> next -> ele;
        }

        const Ele& back() const
        {
            return cursor -> ele;
        }

        void advance()
        {
            cursor = cursor -> next;
        }

        void add(const Ele& e)
        {
            CNode* newCNode = new CNode;
            newCNode -> ele = e;
            if (cursor == NULL) {
                newCNode -> next = newCNode;
                cursor = newCNode;
            }
            else {
                newCNode -> next = cursor -> next;
                cursor -> next = newCNode;
            }
        }

        void remove()
        {
            CNode* old = cursor -> next;
            if (old == cursor) {
                cursor = NULL;
            }
            else {
                cursor -> next = old -> next;
            }
            delete old;
        }

    private:
        CNode* cursor;
};

#endif