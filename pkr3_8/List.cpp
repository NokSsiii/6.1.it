#include "List.h"
#include <iostream>

// Додавання елемента із замиканням кільця
void append(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!head) {
        head = tail = newNode;
        head->next = head; // Замикаємо на себе
        head->prev = head; // Замикаємо на себе
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;

        newNode->next = head; // Новий хвіст вказує на голову
        head->prev = newNode; // Голова вказує на новий хвіст

        tail = newNode;
    }
}

// Виведення списку
void printList(const Node* head) {
    if (!head) {
        std::cout << "[Порожньо]\n";
        return;
    }
    const Node* curr = head;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << std::endl;
}

// Очищення пам'яті
void freeList(Node*& head, Node*& tail) {
    if (!head) return;

    Node* curr = head;
    do {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    } while (curr != head);

    head = tail = nullptr;
}

// Перевірка наявності елемента
bool contains(const Node* head, int value) {
    if (!head) return false;

    const Node* curr = head;
    do {
        if (curr->data == value) return true;
        curr = curr->next;
    } while (curr != head);

    return false;
}

// Об'єднання (Union)
void getUnion(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail) {
    outHead = outTail = nullptr;

    if (head1) {
        const Node* curr = head1;
        do {
            if (!contains(outHead, curr->data)) {
                append(outHead, outTail, curr->data);
            }
            curr = curr->next;
        } while (curr != head1);
    }

    if (head2) {
        const Node* curr = head2;
        do {
            if (!contains(outHead, curr->data)) {
                append(outHead, outTail, curr->data);
            }
            curr = curr->next;
        } while (curr != head2);
    }
}

// Перетин (Intersection)
void getIntersection(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail) {
    outHead = outTail = nullptr;

    if (head1) {
        const Node* curr = head1;
        do {
            if (contains(head2, curr->data) && !contains(outHead, curr->data)) {
                append(outHead, outTail, curr->data);
            }
            curr = curr->next;
        } while (curr != head1);
    }
}

// Різниця (Difference: 1-й список без елементів 2-го)
void getDifference(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail) {
    outHead = outTail = nullptr;

    if (head1) {
        const Node* curr = head1;
        do {
            if (!contains(head2, curr->data) && !contains(outHead, curr->data)) {
                append(outHead, outTail, curr->data);
            }
            curr = curr->next;
        } while (curr != head1);
    }
}