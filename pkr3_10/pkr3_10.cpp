#include <iostream>
#include "ListOperations.h"
#include <windows.h> 

using namespace std;

void fillListFromInput(Node*& head, Node*& tail, int count) {
    cout << "Введіть " << count << " елементів через пробіл: ";
    for (int i = 0; i < count; ++i) {
        int val;
        cin >> val;
        appendNode(head, tail, val);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* list1Head = nullptr; Node* list1Tail = nullptr;
    Node* list2Head = nullptr; Node* list2Tail = nullptr;

    int n1, n2;
    cout << "Введіть кількість елементів першого списку: ";
    cin >> n1;
    if (n1 > 0) fillListFromInput(list1Head, list1Tail, n1);

    cout << "Введіть кількість елементів другого списку: ";
    cin >> n2;
    if (n2 > 0) fillListFromInput(list2Head, list2Tail, n2);

    cout << "\n--- ВХІДНІ СПИСКИ ---\n";
    cout << "Множина A: "; printList(list1Head);
    cout << "Множина B: "; printList(list2Head);
    cout << "---------------------\n";

    // 1. Об'єднання
    Node* unionHead = nullptr; Node* unionTail = nullptr;
    getUnion(list1Head, list2Head, unionHead, unionTail);
    cout << "Об'єднання (A U B): "; printList(unionHead);

    // 2. Різниця (A \ B)
    Node* diffHead = nullptr; Node* diffTail = nullptr;
    getDifference(list1Head, list2Head, diffHead, diffTail);
    cout << "Різниця    (A \\ B): "; printList(diffHead);

    // 3. Перетин
    Node* interHead = nullptr; Node* interTail = nullptr;
    getIntersection(list1Head, list2Head, interHead, interTail);
    cout << "Перетин    (A ∩ B): "; printList(interHead);

    clearList(list1Head, list1Tail);
    clearList(list2Head, list2Tail);
    clearList(unionHead, unionTail);
    clearList(diffHead, diffTail);
    clearList(interHead, interTail);

    return 0;
}