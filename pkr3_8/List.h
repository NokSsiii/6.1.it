#pragma once

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void append(Node*& head, Node*& tail, int value);
void printList(const Node* head);
void freeList(Node*& head, Node*& tail);
bool contains(const Node* head, int value);

void getUnion(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail);
void getIntersection(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail);
void getDifference(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail);