#include "FlightTree.h"
#include <fstream>

// Комбінований ключ: рейс -> дата -> ПІБ
bool isLess(const TicketRequest& a, const TicketRequest& b) {
    if (a.flightNumber != b.flightNumber) return a.flightNumber < b.flightNumber;
    if (a.departureDate != b.departureDate) return a.departureDate < b.departureDate;
    return a.passengerName < b.passengerName;
}

// Додавання елемента
void insertNode(TreeNode*& root, const TicketRequest& req) {
    if (!root) {
        root = new TreeNode{ req, nullptr, nullptr };
        return;
    }
    if (isLess(req, root->data)) {
        insertNode(root->left, req);
    }
    else {
        insertNode(root->right, req);
    }
}

// Допоміжний пошук мінімуму
TreeNode* findMin(TreeNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Видалення вузла
TreeNode* removeNode(TreeNode* root, const TicketRequest& req, bool& success) {
    if (!root) return nullptr;

    if (isLess(req, root->data)) {
        root->left = removeNode(root->left, req, success);
    }
    else if (isLess(root->data, req)) {
        root->right = removeNode(root->right, req, success);
    }
    else {
        success = true;
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data, success);
    }
    return root;
}

// Очищення пам'яті
void clearTree(TreeNode*& root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
    root = nullptr;
}


// балансування
// Розгортає дерево в лінійний список, використовуючи покажчики right (left стають nullptr)
void flattenInOrder(TreeNode* root, TreeNode*& head, TreeNode*& tail) {
    if (!root) return;

    flattenInOrder(root->left, head, tail);

    TreeNode* rightSide = root->right; // Запам'ятовуємо, бо right затреться
    root->left = nullptr;

    if (!head) {
        head = root;
    }
    else {
        tail->right = root;
    }
    tail = root;

    flattenInOrder(rightSide, head, tail);
}

// Рахує вузли у списку/дереві
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Збирає ідеально збалансоване дерево з лінійного списку елементів
TreeNode* buildBalancedFromList(TreeNode*& head, int n) {
    if (n <= 0 || !head) return nullptr;

    TreeNode* leftChild = buildBalancedFromList(head, n / 2);

    TreeNode* root = head;
    root->left = leftChild;
    head = head->right; // Зсуваємо голову списку вперед

    root->right = buildBalancedFromList(head, n - n / 2 - 1);

    return root;
}

// Головна функція балансування
void balanceTree(TreeNode*& root) {
    if (!root) return;

    int n = countNodes(root);
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    flattenInOrder(root, head, tail);
    if (tail) tail->right = nullptr; // Надійно закриваємо хвіст списку

    root = buildBalancedFromList(head, n);
}

// вибірка
// Шукає перший-ліпший збіг рейсу та дати у дереві
TreeNode* findMatch(TreeNode* root, const std::string& flightNum, const std::string& date) {
    if (!root) return nullptr;
    if (root->data.flightNumber == flightNum && root->data.departureDate == date) return root;

    TreeNode* leftRes = findMatch(root->left, flightNum, date);
    if (leftRes) return leftRes;

    return findMatch(root->right, flightNum, date);
}

// Знаходить, копіює в нове дерево та видаляє з оригінального
TreeNode* extractAndRemoveByFlightAndDate(TreeNode*& root, const std::string& flightNum, const std::string& date) {
    TreeNode* resultTree = nullptr;

    while (true) {
        TreeNode* match = findMatch(root, flightNum, date);
        if (!match) break; // Збігів більше немає

        // Додаємо копію в нове дерево результатів
        insertNode(resultTree, match->data);

        // Видаляємо з основного дерева за допомогою стандартного removeNode
        bool success = false;
        root = removeNode(root, match->data, success);
    }
    return resultTree;
}

// --- ФАЙЛОВІ ОПЕРАЦІЇ ---

void savePreOrder(TreeNode* root, std::ofstream& out) {
    if (!root) return;
    out << root->data.destination << "\n"
        << root->data.flightNumber << "\n"
        << root->data.passengerName << "\n"
        << root->data.departureDate << "\n";
    savePreOrder(root->left, out);
    savePreOrder(root->right, out);
}

bool saveToFile(TreeNode* root, const std::string& filename) {
    std::ofstream out(filename);
    if (!out.is_open()) return false;
    savePreOrder(root, out);
    out.close();
    return true;
}

bool loadFromFile(TreeNode*& root, const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) return false;

    clearTree(root);

    std::string dest, flight, name, date;
    while (std::getline(in, dest) && std::getline(in, flight) &&
        std::getline(in, name) && std::getline(in, date)) {
        TicketRequest req{ dest, flight, name, date };
        insertNode(root, req);
    }
    in.close();
    return true;
}