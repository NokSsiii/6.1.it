#pragma once

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value);
void appendNode(Node*& head, Node*& tail, int value);
void clearList(Node*& head, Node*& tail);
void printList(const Node* head);

bool contains(const Node* head, int value);

void getUnion(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail);
void getIntersection(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail);
void getDifference(const Node* head1, const Node* head2, Node*& outHead, Node*& outTail);