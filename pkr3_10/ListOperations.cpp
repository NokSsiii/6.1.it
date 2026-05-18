#include "ListOperations.h"
#include <iostream>

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void appendNode(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void clearList(Node*& head, Node*& tail) {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

void printList(const Node* head) {
    if (!head) {
        std::cout << "—писок порожн≥й.";
    }
    const Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool contains(const Node* head, int value) {
    const Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void getUnion(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail) {
    const Node* curr1 = head1;
    while (curr1) {
        if (!contains(outHead, curr1->data)) {
            appendNode(outHead, outTail, curr1->data);
        }
        curr1 = curr1->next;
    }
    const Node* curr2 = head2;
    while (curr2) {
        if (!contains(outHead, curr2->data)) {
            appendNode(outHead, outTail, curr2->data);
        }
        curr2 = curr2->next;
    }
}

void getIntersection(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail) {
    const Node* curr1 = head1;
    while (curr1) {
        // якщо елемент Ї в другому списку ≥ ще не доданий до результату
        if (contains(head2, curr1->data) && !contains(outHead, curr1->data)) {
            appendNode(outHead, outTail, curr1->data);
        }
        curr1 = curr1->next;
    }
}

void getDifference(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail) {
    const Node* curr1 = head1;
    while (curr1) {
        // якщо елементу немаЇ в другому списку ≥ в≥н ще не доданий до результату
        if (!contains(head2, curr1->data) && !contains(outHead, curr1->data)) {
            appendNode(outHead, outTail, curr1->data);
        }
        curr1 = curr1->next;
    }
}