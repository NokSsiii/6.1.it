#include <iostream>
#include "List.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head1 = nullptr; Node* tail1 = nullptr;
    Node* head2 = nullptr; Node* tail2 = nullptr;

    std::cout << "--- Формування першого кільцевого списку ---\n";
    std::cout << "Введіть кількість елементів: ";
    int n1;
    std::cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int val;
        std::cout << "Елемент " << i + 1 << ": ";
        std::cin >> val;
        append(head1, tail1, val);
    }

    std::cout << "\n--- Формування другого кільцевого списку ---\n";
    std::cout << "Введіть кількість елементів: ";
    int n2;
    std::cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int val;
        std::cout << "Елемент " << i + 1 << ": ";
        std::cin >> val;
        append(head2, tail2, val);
    }

    std::cout << "\n=== Вхідні списки ===\n";
    std::cout << "Список 1: "; printList(head1);
    std::cout << "Список 2: "; printList(head2);

    Node* unionHead = nullptr; Node* unionTail = nullptr;
    Node* interHead = nullptr; Node* interTail = nullptr;
    Node* diffHead = nullptr;  Node* diffTail = nullptr;

    getUnion(head1, head2, unionHead, unionTail);
    getIntersection(head1, head2, interHead, interTail);
    getDifference(head1, head2, diffHead, diffTail);

    std::cout << "\n=== Результати ===\n";
    std::cout << "Об'єднання (Union): "; printList(unionHead);
    std::cout << "Перетин (Intersection): "; printList(interHead);
    std::cout << "Різниця (List1 \\ List2): "; printList(diffHead);

    freeList(head1, tail1);
    freeList(head2, tail2);
    freeList(unionHead, unionTail);
    freeList(interHead, interTail);
    freeList(diffHead, diffTail);

    return 0;
}