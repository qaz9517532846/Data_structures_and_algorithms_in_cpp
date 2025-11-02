#include "NodeList.h"

NodeList::Iterator::Iterator(Node* u)
{
    v = u;
}

Elem& NodeList::Iterator::operator*()
{
    return v->elem;
}

bool NodeList::Iterator::operator==(const Iterator& p) const
{
    return v == p.v;
}

bool NodeList::Iterator::operator!=(const Iterator& p) const
{
    return v != p.v;
}

NodeList::Iterator& NodeList::Iterator::operator++()
{
    v = v->next;
    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

NodeList::NodeList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

int NodeList::size() const
{
    return n;
}

bool NodeList::empty() const
{
    return n == 0;
}

NodeList::Iterator NodeList::begin() const
{
    return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const
{
    return Iterator(trailer);
}

void NodeList::insert(const Iterator& p, const Elem& e)
{
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w;
    v->prev = u;
    u->next = v;
    w->prev = v;
    n++;
}

void NodeList::insertFront(const Elem& e)
{
    insert(begin(), e);
}

void NodeList::insertBack(const Elem& e)
{
    insert(end(), e);
}

void NodeList::erase(const Iterator& p)
{
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

void NodeList::eraseFront()
{
    erase(begin());
}

void NodeList::eraseBack()
{
    erase(--end());
}

NodeSequence::Iterator NodeSequence::atIndex(int i) const
{
    Iterator p = begin();
    for (int j = 0; j < i; j++) {
        ++p;
    }
    return p;
}

int NodeSequence::indexOf(const Iterator& p) const
{
    Iterator q = begin();
    int j = 0;
    while (q != p) {
        ++q;
        ++j;
    }
    return j;
}

void bubbleSort1(NodeSequence& S)
{
    int n = S.size();
    for (int i = 0; i < n; i++) {
        for(int j = 1; j < n - i; j++) {
            NodeSequence::Iterator prec = S.atIndex(j - 1);
            NodeSequence::Iterator succ = S.atIndex(j);
            if (*prec > *succ) {
                Elem temp = *prec;
                *prec = *succ;
                *succ = temp;
            }
        }
    }
}

void bubbleSort2(NodeSequence& S)
{
    int n = S.size();
    for (int i = 0; i < n; i++) {
        NodeSequence::Iterator prec = S.begin();
        for(int j = 1; j < n - i; j++) {
            NodeSequence::Iterator succ = prec;
            ++succ;
            if (*prec > *succ) {
                Elem temp = *prec;
                *prec = *succ;
                *succ = temp;
            }
            ++prec;
        }
    }
}

int main()
{
    NodeList nl;
    nl.insertBack("Alice");
    nl.insertBack("Bob");
    nl.insertFront("Eve");

    for (NodeList::Iterator it = nl.begin(); it != nl.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    nl.eraseFront();
    nl.eraseBack();

    for (NodeList::Iterator it = nl.begin(); it != nl.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}