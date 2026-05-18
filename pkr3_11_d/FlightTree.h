#pragma once
#include <string>

struct TicketRequest {
    std::string destination;      
    std::string flightNumber;    
    std::string passengerName;   
    std::string departureDate;
};

struct TreeNode {
    TicketRequest data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

bool isLess(const TicketRequest& a, const TicketRequest& b);

void insertNode(TreeNode*& root, const TicketRequest& req);
TreeNode* removeNode(TreeNode* root, const TicketRequest& req, bool& success);
void clearTree(TreeNode*& root);

// Чисте балансування на покажчиках
void flattenInOrder(TreeNode* root, TreeNode*& head, TreeNode*& tail);
TreeNode* buildBalancedFromList(TreeNode*& head, int n);
int countNodes(TreeNode* root);
void balanceTree(TreeNode*& root);

// Пошук та вилучення за варіантом
TreeNode* findMatch(TreeNode* root, const std::string& flightNum, const std::string& date);
TreeNode* extractAndRemoveByFlightAndDate(TreeNode*& root, const std::string& flightNum, const std::string& date);

// Робота з файлами
void savePreOrder(TreeNode* root, std::ofstream& out);
bool saveToFile(TreeNode* root, const std::string& filename);
bool loadFromFile(TreeNode*& root, const std::string& filename);