#pragma once
#include <cstddef>
#include <stdexcept>

class NullIterator {}; // Клас винятків для ітератора

class List {
public:
    typedef double value_type;
    typedef size_t size_type;
    class iterator;

    // Конструктори, копіювання, присвоєння
    List();
    List(const value_type& a, size_type n = 1);
    List(iterator first, iterator last);
    List(const List& r);
    ~List();
    List& operator=(const List& r);

    // Ітератори
    iterator begin() { return head; }
    iterator end() { return tail; }
    iterator begin() const { return head; }
    iterator end() const { return tail; }

    // Розміри
    bool empty() const { return (Head == Tail); }
    size_type lenght() const { return count; } // збережено оригінальну назву з помилкою з лістингу

    // Доступ до елементів
    value_type& front() { return *begin(); }
    value_type& back() { iterator it = end(); --it; return *it; }

    // Модифікатори
    void push_front(const value_type&);
    value_type pop_front();
    void push_back(const value_type&);
    value_type pop_back();
    void insert(iterator it, const value_type& r);
    void erase(iterator it);
    void swap(List& L);
    void clear();

private:
    struct Node {
        Node(const value_type& a) : item(a), next(nullptr), prev(nullptr) {}
        Node() : item(0), next(nullptr), prev(nullptr) {}
        value_type item;
        Node* next;
        Node* prev;
    };

    long count;
    Node* Head;
    Node* Tail;

public:
    class iterator {
        friend class List;
        Node* elem;
        iterator(Node* el) : elem(el) {}
    public:
        iterator() : elem(nullptr) {}
        iterator(const iterator& it) : elem(it.elem) {}

        bool operator==(const iterator& it) const { return elem == it.elem; }
        bool operator!=(const iterator& it) const { return elem != it.elem; }

        iterator& operator++() {
            if (elem != nullptr) elem = elem->next;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        iterator& operator--() {
            if (elem != nullptr) elem = elem->prev;
            return *this;
        }
        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        value_type& operator*() {
            if (elem != nullptr) return elem->item;
            else throw NullIterator();
        }
    };

private:
    iterator head, tail;
};