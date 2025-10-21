// ...existing code...
#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

template<typename E>
class SLinkedList {
private:
    struct Node {
        E elem;
        Node* next;
        Node(const E& e = E(), Node* n = nullptr) : elem(e), next(n) {}
    };

    Node* head;

public:
    SLinkedList() : head(nullptr) {}
    ~SLinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void addFront(const E& e) {
        head = new Node(e, head);
    }

    void removeFront() {
        if (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    E& front() {
        return head->elem;
    }

    const E& front() const {
        return head->elem;
    }

    bool empty() const {
        return head == nullptr;
    }
};

#endif // SLINKEDLIST_H
// ...existing code...