#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TreeOperations.h"
#include <Windows.h>

using namespace std;

void showMenu() {
    cout << "\n--- МЕНЮ РОБОТИ З ДЕРЕВОМ ---\n";
    cout << "1. Створити звичайне бінарне дерево (N елементів)\n";
    cout << "2. Створити бінарне дерево пошуку (N елементів)\n";
    cout << "3. Додати елемент в дерево пошуку\n";
    cout << "4. Видалити вузол за ключем (опрацьовує 0, 1 або 2 нащадки)\n";
    cout << "5. Видалити цілу гілку (дерево) повністю\n";
    cout << "6. Збалансувати дерево пошуку\n";
    cout << "7. Знайти кількість входжень числа K (Варіант 24)\n";
    cout << "8. Вивести дерево на екран\n";
    cout << "0. Вихід\n";
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(static_cast<unsigned>(time(0)));

    TreeNode* root = nullptr;
    int choice, n, val;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            clearTree(root);
            root = createBinaryTree(n);
            cout << "Звичайне дерево створено.\n";
            break;
        case 2:
            cout << "Введіть кількість елементів: ";
            cin >> n;
            clearTree(root);
            root = createBST(n);
            cout << "Бінарне дерево пошуку створено.\n";
            break;
        case 3:
            cout << "Введіть значення для додавання: ";
            cin >> val;
            root = insertBST(root, val);
            cout << "Елемент додано.\n";
            break;
        case 4:
            cout << "Введіть значення вузла для видалення: ";
            cin >> val;
            root = deleteNode(root, val);
            cout << "Видалення виконано.\n";
            break;
        case 5:
            clearTree(root);
            cout << "Дерево (або його корінь з усіма гілками) видалено.\n";
            break;
        case 6:
            root = balanceBST(root);
            cout << "Дерево збалансовано.\n";
            break;
        case 7:
            cout << "Введіть значення K для пошуку: ";
            cin >> val;
            cout << "Кількість входжень числа " << val << " у дерево: "
                << countOccurrences(root, val) << "\n";
            break;
        case 8:
            cout << "\n--- СТРУКТУРА ДЕРЕВА ---\n";
            printTree(root, 0, root); // Поточний елемент (корінь) буде виділено [ ]
            cout << "------------------------\n";
            break;
        case 0:
            clearTree(root);
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}