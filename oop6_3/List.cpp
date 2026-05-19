#include "List.h"
#include <algorithm>

List::List() : Head(new Node()), Tail(Head), count(0) {
    Tail->next = Tail->prev = nullptr;
    head = iterator(Head);
    tail = iterator(Tail);
}

List::List(const value_type& a, size_type n) : List() {
    for (size_type i = 0; i < n; i++) {
        push_front(a);
    }
}

List::List(iterator first, iterator last) : List() {
    for (iterator ip = first; ip != last; ip++) {
        push_back(*ip);
    }
}

List::List(const List& r) : List() {
    for (iterator ip = r.begin(); ip != r.end(); ip++) {
        push_back(*ip);
    }
}

List::~List() {
    clear();
    delete Tail;
}

List& List::operator=(const List& t) {
    if (this != &t) {
        List tmp(t);
        swap(tmp);
    }
    return *this;
}

void List::insert(iterator it, const value_type& r) {
    if (it == end()) {
        push_back(r);
    }
    else {
        Node* el = it.elem;
        Node* next_el = el->next;
        Node* p = new Node(r);
        p->next = next_el;
        p->prev = el;
        if (next_el != nullptr) next_el->prev = p;
        el->next = p;
        ++count;
    }
}

void List::erase(iterator it) {
    if (it == end()) return;
    if (it == begin()) {
        pop_front();
    }
    else {
        Node* el = it.elem;
        Node* prev_el = el->prev;
        Node* next_el = el->next;
        prev_el->next = next_el;
        if (next_el != nullptr) next_el->prev = prev_el;
        delete el;
        --count;
    }
}

void List::push_front(const value_type& v) {
    Node* p = new Node(v);
    p->next = Head;
    if (Head != Tail) {
        Head->prev = p;
    }
    else {
        Tail->prev = p;
    }
    Head = p;
    head = iterator(Head);
    ++count;
}

void List::push_back(const value_type& v) {
    Node* p = new Node(v);
    p->next = Tail;
    if (Head == Tail) {
        p->prev = nullptr;
        Head = p;
        head = iterator(Head);
    }
    else {
        Node* last = Tail->prev;
        p->prev = last;
        last->next = p;
    }
    Tail->prev = p;
    ++count;
}

List::value_type List::pop_front() {
    if (empty()) throw std::runtime_error("List is empty");
    Node* oldHead = Head;
    value_type val = oldHead->item;
    Head = Head->next;
    if (Head != nullptr) Head->prev = nullptr;
    head = iterator(Head);
    delete oldHead;
    --count;
    return val;
}

List::value_type List::pop_back() {
    if (empty()) throw std::runtime_error("List is empty");
    Node* last = Tail->prev;
    value_type val = last->item;
    if (last->prev != nullptr) {
        last->prev->next = Tail;
        Tail->prev = last->prev;
    }
    else {
        Head = Tail;
        Tail->prev = nullptr;
        head = iterator(Head);
    }
    delete last;
    --count;
    return val;
}

void List::swap(List& L) {
    std::swap(Head, L.Head);
    std::swap(Tail, L.Tail);
    std::swap(count, L.count);
    std::swap(head, L.head);
    std::swap(tail, L.tail);
}

void List::clear() {
    while (!empty()) {
        pop_front();
    }
}