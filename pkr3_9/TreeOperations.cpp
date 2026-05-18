#include "TreeOperations.h"
#include <iostream>
#include <vector>

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 1. Створення простого бінарного дерева (заповнення випадково)
TreeNode* createBinaryTree(int n) {
    if (n <= 0) return nullptr;
    TreeNode* root = createNode(rand() % 100);
    // Спрощена логіка: лівому піддереву віддаємо половину вузлів, правому - решту
    root->left = createBinaryTree(n / 2);
    root->right = createBinaryTree(n - 1 - n / 2);
    return root;
}

// 4. Додавання нового елемента із збереженням порядку (BST)
TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) return createNode(value);

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

// 3. Створення бінарного дерева пошуку (BST)
TreeNode* createBST(int n) {
    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = insertBST(root, rand() % 100);
    }
    return root;
}

// 2. Вивід дерева на екран (з виділенням поточного елемента маркерами [ ])
void printTree(TreeNode* root, int space, TreeNode* current) {
    if (!root) return;
    space += 5;
    printTree(root->right, space, current);

    std::cout << std::endl;
    for (int i = 5; i < space; i++) std::cout << " ";

    if (root == current) {
        std::cout << "[" << root->data << "]\n";
    }
    else {
        std::cout << root->data << "\n";
    }

    printTree(root->left, space, current);
}

// 5. Збалансування дерева пошуку (через In-order обхід)
void storeInOrder(TreeNode* root, std::vector<TreeNode*>& nodes) {
    if (!root) return;
    storeInOrder(root->left, nodes);
    nodes.push_back(root);
    storeInOrder(root->right, nodes);
}

TreeNode* buildBalanced(std::vector<TreeNode*>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = nodes[mid];
    root->left = buildBalanced(nodes, start, mid - 1);
    root->right = buildBalanced(nodes, mid + 1, end);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    std::vector<TreeNode*> nodes;
    storeInOrder(root, nodes);
    return buildBalanced(nodes, 0, (int)nodes.size() - 1);
}

// Знаходження мінімального вузла (для видалення)
TreeNode* getMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// 6, 7, 8. Видалення елемента (універсальна функція для 0, 1 або 2 дочірніх вузлів)
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Випадок 1 та 2: вузол з 0 або 1 дочірнім вузлом
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
        // Випадок 3: вузол з 2 дочірніми вузлами
        TreeNode* temp = getMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 9. Видалення гілки (елемента з усіма його нащадками)
void deleteSubtree(TreeNode*& root) {
    if (!root) return;
    deleteSubtree(root->left);
    deleteSubtree(root->right);
    delete root;
    root = nullptr;
}

void clearTree(TreeNode*& root) {
    deleteSubtree(root);
}

// 10.Підрахунок входжень елемента k
int countOccurrences(TreeNode* root, int k) {
    if (!root) return 0;
    int count = (root->data == k) ? 1 : 0;
    return count + countOccurrences(root->left, k) + countOccurrences(root->right, k);
}