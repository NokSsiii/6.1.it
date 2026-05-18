#include "EmployeeTree.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

// --- ДОПОМІЖНІ ФУНКЦІЇ ДЛЯ ДЕРЕВА ---

// Пошук мінімального вузла (потрібен для видалення)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Рекурсивне додавання елемента в BST за ПІБ
void addEmployee(Node*& root, const Employee& emp) {
    if (!root) {
        root = new Node{ emp, nullptr, nullptr };
        return;
    }
    if (emp.fullName < root->data.fullName) {
        addEmployee(root->left, emp);
    }
    else {
        addEmployee(root->right, emp);
    }
}

// Пошук у дереві за ПІБ
Node* searchEmployee(Node* root, const std::string& fullName) {
    if (!root || root->data.fullName == fullName) return root;
    if (fullName < root->data.fullName) return searchEmployee(root->left, fullName);
    return searchEmployee(root->right, fullName);
}

// Внутрішня рекурсивна функція для видалення вузла
Node* removeNodeInternal(Node* root, const std::string& fullName, bool& success) {
    if (!root) {
        success = false;
        return nullptr;
    }
    if (fullName < root->data.fullName) {
        root->left = removeNodeInternal(root->left, fullName, success);
    }
    else if (fullName > root->data.fullName) {
        root->right = removeNodeInternal(root->right, fullName, success);
    }
    else {
        success = true;
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNodeInternal(root->right, temp->data.fullName, success);
    }
    return root;
}

// Публічний інтерфейс видалення
bool removeEmployee(Node*& root, const std::string& fullName) {
    bool success = false;
    root = removeNodeInternal(root, fullName, success);
    return success;
}

// Редагування даних
bool editEmployee(Node*& root, const std::string& oldFullName, const Employee& newEmp) {
    Node* target = searchEmployee(root, oldFullName);
    if (!target) return false;

    if (oldFullName == newEmp.fullName) {
        target->data = newEmp;
    }
    else {
        removeEmployee(root, oldFullName);
        addEmployee(root, newEmp);
    }
    return true;
}

// Повне очищення пам'яті дерева
void clearTree(Node*& root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
    root = nullptr;
}


// --- АЛГОРИТМИ IN-PLACE БАЛАНСУВАННЯ ТА СОРТУВАННЯ (БЕЗ ВЕКТОРІВ) ---

// Трансформація дерева у правий однозв'язний список методом правої ротації (Алгоритм DSW)
Node* flattenToVine(Node* root) {
    Node dummy;
    dummy.right = root;
    dummy.left = nullptr;
    Node* p = &dummy;
    Node* vine = p->right;

    while (vine) {
        if (vine->left) {
            Node* oldLeft = vine->left;
            vine->left = oldLeft->right;
            oldLeft->right = vine;
            p->right = oldLeft;
            vine = oldLeft;
        }
        else {
            p = vine;
            vine = vine->right;
        }
    }
    return dummy.right;
}

// Підрахунок кількості вузлів у лінійній структурі
int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->right;
    }
    return count;
}

// Рекурсивна побудова збалансованого BST з відсортованого лінійного списку
Node* buildBalancedBST(Node*& head, int n) {
    if (n <= 0) return nullptr;

    Node* leftTree = buildBalancedBST(head, n / 2);

    Node* root = head;
    head = head->right;

    root->left = leftTree;
    root->right = buildBalancedBST(head, n - n / 2 - 1);

    return root;
}

// Функція балансування дерева
void balanceTree(Node*& root) {
    if (!root) return;
    Node* head = flattenToVine(root);
    int n = countNodes(head);
    root = buildBalancedBST(head, n);
}

// Сортування та виведення на екран (без копіювання у вектор)
void sortAndPrint(Node*& root, int criteria) {
    if (!root) {
        std::cout << "Дерево порожнє.\n";
        return;
    }

    // 1. Перетворюємо дерево на лінійний список
    Node* head = flattenToVine(root);

    // 2. Сортуємо дані методом бульбашки безпосередньо у вузлах за обраним критерієм
    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr && curr->right) {
            bool condition = false;
            if (criteria == 1) condition = curr->data.fullName > curr->right->data.fullName;
            else if (criteria == 2) condition = curr->data.salary > curr->right->data.salary;
            else if (criteria == 3) condition = curr->data.yearHired > curr->right->data.yearHired;

            if (condition) {
                std::swap(curr->data, curr->right->data);
                swapped = true;
            }
            curr = curr->right;
        }
    } while (swapped);

    // 3. Виводимо відсортований результат
    Node* temp = head;
    while (temp) {
        printEmployee(temp->data);
        temp = temp->right;
    }

    // 4. Повертаємо базове сортування за ПІБ (якщо сортували за чимось іншим), щоб відновити інваріант BST
    if (criteria != 1) {
        do {
            swapped = false;
            Node* curr = head;
            while (curr && curr->right) {
                if (curr->data.fullName > curr->right->data.fullName) {
                    std::swap(curr->data, curr->right->data);
                    swapped = true;
                }
                curr = curr->right;
            }
        } while (swapped);
    }

    // 5. Перескладаємо лінійну структуру назад у збалансоване дерево пошуку
    int n = countNodes(head);
    root = buildBalancedBST(head, n);
}


// --- ФАЙЛОВІ ОПЕРАЦІЇ ---

// Прямий обхід (Pre-order) для коректного збереження структури зв'язків дерева
void savePreOrder(Node* root, std::ofstream& file) {
    if (!root) return;
    file << root->data.fullName << '\n' << root->data.position << '\n'
        << root->data.yearHired << '\n' << root->data.salary << '\n';
    savePreOrder(root->left, file);
    savePreOrder(root->right, file);
}

bool saveToFile(Node* root, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    savePreOrder(root, file);
    file.close();
    return true;
}

bool loadFromFile(Node*& root, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    clearTree(root);
    Employee emp;
    std::string yearStr, salaryStr;

    while (std::getline(file, emp.fullName)) {
        std::getline(file, emp.position);
        std::getline(file, yearStr);
        std::getline(file, salaryStr);
        try {
            emp.yearHired = std::stoi(yearStr);
            emp.salary = std::stod(salaryStr);
            addEmployee(root, emp);
        }
        catch (...) {
            file.close();
            return false;
        }
    }
    file.close();
    balanceTree(root); // Автоматично балансуємо після завантаження
    return true;
}


// --- ВАЛІДАЦІЯ ВВОДУ ТА ВИВЕДЕННЯ ---

int getIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка вводу. Спробуйте ще раз.\n";
    }
}

double getDoubleInput(const std::string& prompt, double min, double max) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка вводу. Спробуйте ще раз.\n";
    }
}

std::string getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

void printEmployee(const Employee& emp) {
    std::cout << "ПІБ: " << emp.fullName
        << " | Посада: " << emp.position
        << " | Рік прийому: " << emp.yearHired
        << " | Оклад: " << emp.salary << " грн\n";
}

void printTreeInOrder(Node* root) {
    if (!root) return;
    printTreeInOrder(root->left);
    printEmployee(root->data);
    printTreeInOrder(root->right);
}