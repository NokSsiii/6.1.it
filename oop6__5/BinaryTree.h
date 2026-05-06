#pragma once
#include <iostream>
#include <list>
#include "TreeException.h"

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    std::list<Node> storage;
    Node* root;

    void printInOrderHelper(Node* node) const {
        if (node != nullptr) {
            printInOrderHelper(node->left);
            std::cout << node->data << " ";
            printInOrderHelper(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& value) {
        if (root == nullptr) {
            storage.push_back(Node(value));
            root = &storage.back();
            return;
        }

        Node* current = root;
        while (true) {
            if (value == current->data) {
                throw TreeException("Error: Element already exists in the tree (duplicate).");
            }
            else if (value < current->data) {
                if (current->left == nullptr) {
                    storage.push_back(Node(value));
                    current->left = &storage.back();
                    break;
                }
                current = current->left;
            }
            else {
                if (current->right == nullptr) {
                    storage.push_back(Node(value));
                    current->right = &storage.back();
                    break;
                }
                current = current->right;
            }
        }
    }

    T getMin() const {
        if (root == nullptr) {
            throw TreeException("Error: Tree is empty, cannot find minimum element.");
        }
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    void printInOrder() const {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }
        printInOrderHelper(root);
        std::cout << std::endl;
    }
};