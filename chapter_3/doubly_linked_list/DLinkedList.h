#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H 1

using namespace std;

typedef string Elem;

class DNode {
    private:
        Elem elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList;
};

class DLinkedList {
    private:
        DNode* header;
        DNode* trailer;
    protected:
        void add(DNode* v, const Elem& e);
        void remove(DNode* v);
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const Elem& front() const;
        const Elem& back() const;
        void addFront(const Elem& e);
        void addBack(const Elem& e);
        void removeFront();
        void removeBack();
        void printList() const;
        void rprintList() const;
};



#endif
