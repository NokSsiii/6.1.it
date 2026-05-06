#include <iostream>
#include <string>
#include "BinaryTree.h"

void testInt() {
    std::cout << "--- Test BinaryTree<int> ---" << std::endl;
    BinaryTree<int> tree;
    try { tree.getMin(); }
    catch (const TreeException& e) { std::cout << e.what() << std::endl; }
    tree.insert(50); tree.insert(30); tree.insert(70);
    tree.printInOrder();
    try { tree.insert(30); }
    catch (const TreeException& e) { std::cout << e.what() << std::endl; }
}

void testDouble() {
    std::cout << "\n--- Test BinaryTree<double> ---" << std::endl;
    BinaryTree<double> tree;
    tree.insert(3.14); tree.insert(2.71); tree.insert(4.0);
    tree.printInOrder();
    std::cout << "Minimum: " << tree.getMin() << std::endl;
}

void testString() {
    std::cout << "\n--- Test BinaryTree<std::string> ---" << std::endl;
    BinaryTree<std::string> tree;
    tree.insert("Orange"); tree.insert("Apple"); tree.insert("Banana");
    tree.printInOrder();
}

int main() {
    testInt();
    testDouble();
    testString();
    return 0;
}