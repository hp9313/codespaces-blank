#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void add(int d) {
        Node* n = new Node(d);
        if (!head) {
            head = n;
        } else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    void print() {
        Node* t = head;
        while (t) {
            std::cout << t->data << " ";
            t = t->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }
};

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();
    return 0;
}