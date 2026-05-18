#pragma once
#include <vector>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value);
TreeNode* createBinaryTree(int n);
TreeNode* createBST(int n);
void printTree(TreeNode* root, int space = 0, TreeNode* current = nullptr);
void clearTree(TreeNode*& root);

TreeNode* insertBST(TreeNode* root, int value);
TreeNode* deleteNode(TreeNode* root, int key);
void deleteSubtree(TreeNode*& root);

void storeInOrder(TreeNode* root, std::vector<TreeNode*>& nodes);
TreeNode* buildBalanced(std::vector<TreeNode*>& nodes, int start, int end);
TreeNode* balanceBST(TreeNode* root);

int countOccurrences(TreeNode* root, int k);