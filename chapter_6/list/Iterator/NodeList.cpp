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