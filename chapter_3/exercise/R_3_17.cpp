#include <iostream>

using namespace std;

typedef string Ele;

class CNode {
    private:
        Ele ele;
        CNode* next;

    friend class CLinkedList;
};

class CLinkedList {
    private:
        CNode* cursor;

    public:
        CLinkedList();
        ~CLinkedList();
        void add(const Ele& e);
        int count();
};

CLinkedList::CLinkedList() {
    cursor = NULL;
}

CLinkedList::~CLinkedList() {

}

void CLinkedList::add(const Ele& e) {
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

int CLinkedList::count()
{
    if(cursor == NULL)  return 0;
    else
    {
        int cnt = 1;
        CNode* current = cursor->next;

        while (current != cursor)
        {
            cnt++;
            current = current->next;
        }

        return cnt;
    }
}

int main(void) {
    CLinkedList clist;

    // adding elements in list
    clist.add("Afrid");
    clist.add("Bhavana");
    clist.add("AB");

    // Is list empty?
    cout << "Circle Link list size : " << clist.count() << endl;

    return 0;
}