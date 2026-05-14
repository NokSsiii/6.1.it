#pragma once
#include <iostream>
#include <stdexcept>

class NullIterator {};

template<class T>
class List
{
public:
    typedef T value_type;
    typedef size_t size_type;

private:
    struct Node
    {
        Node(const value_type& a) : item(a), next(nullptr), prev(nullptr) {}
        Node() : item(), next(nullptr), prev(nullptr) {}

        value_type item;
        Node* next;
        Node* prev;
    };

public:
    class iterator
    {
        friend class List<T>;
        Node* elem;

        iterator(Node* el) : elem(el) {}

    public:
        iterator() : elem(nullptr) {}
        iterator(const iterator& it) : elem(it.elem) {}

        bool operator==(const iterator& it) const { return elem == it.elem; }
        bool operator!=(const iterator& it) const { return elem != it.elem; }

        iterator& operator++()
        {
            if (elem != nullptr)
                elem = elem->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        iterator& operator--()
        {
            if (elem != nullptr)
                elem = elem->prev;
            return *this;
        }

        iterator operator--(int)
        {
            iterator tmp(*this);
            --(*this);
            return tmp;
        }

        iterator& operator+=(int n)
        {
            while (n-- > 0 && elem != nullptr)
                elem = elem->next;
            return *this;
        }

        iterator& operator-=(int n)
        {
            while (n-- > 0 && elem != nullptr)
                elem = elem->prev;
            return *this;
        }

        value_type& operator*()
        {
            if (elem != nullptr)
                return elem->item;
            throw NullIterator();
        }
    };

private:
    long count;
    Node* Head;
    Node* Tail;
    iterator head, tail;

public:
    // конструктори
    List() : Head(new Node()), Tail(Head), count(0)
    {
        Tail->next = Tail->prev = nullptr;
        head = iterator(Head);
        tail = iterator(Tail);
    }

    List(const value_type& a, size_type n = 1) : List()
    {
        for (size_type i = 0; i < n; i++)
            push_back(a);
    }

    List(iterator first, iterator last) : List()
    {
        for (iterator it = first; it != last; it++)
            push_back(*it);
    }

    List(const List& r) : List()
    {
        for (iterator it = r.begin(); it != r.end(); it++)
            push_back(*it);
    }

    ~List()
    {
        clear();
        delete Head;
        Head = Tail = nullptr;
        count = 0;
    }

    List& operator=(const List& r)
    {
        if (this == &r) return *this;
        List tmp(r);
        swap(tmp);
        return *this;
    }

    // ітератори
    iterator begin() { return iterator(Head->next); }
    iterator end() { return iterator(Tail); }

    iterator begin() const { return iterator(Head->next); }
    iterator end() const { return iterator(Tail); }

    // розміри
    bool empty() const { return count == 0; }
    size_type length() const { return count; }
    size_type size() const { return count; }

    // доступ
    value_type& front()
    {
        if (empty()) throw std::runtime_error("List is empty");
        return *begin();
    }

    value_type& back()
    {
        if (empty()) throw std::runtime_error("List is empty");
        iterator it = end();
        --it;
        return *it;
    }

    iterator find(const value_type& a)
    {
        for (iterator it = begin(); it != end(); it++)
        {
            if (*it == a)
                return it;
        }
        return end();
    }

    // модифікатори
    void push_front(const value_type& v)
    {
        Node* p = new Node(v);

        if (count == 0)
        {
            Head->next = p;
            p->prev = Head;
            p->next = Tail;
            Tail->prev = p;
        }
        else
        {
            Node* first = Head->next;
            p->next = first;
            p->prev = Head;
            first->prev = p;
            Head->next = p;
        }
        count++;
    }

    value_type pop_front()
    {
        if (empty()) throw std::runtime_error("List is empty");
        Node* first = Head->next;
        value_type val = first->item;

        Node* second = first->next;
        Head->next = second;
        second->prev = Head;

        delete first;
        count--;
        return val;
    }

    void push_back(const value_type& v)
    {
        Node* p = new Node(v);

        if (count == 0)
        {
            Head->next = p;
            p->prev = Head;
            p->next = Tail;
            Tail->prev = p;
        }
        else
        {
            Node* last = Tail->prev;
            last->next = p;
            p->prev = last;
            p->next = Tail;
            Tail->prev = p;
        }
        count++;
    }

    value_type pop_back()
    {
        if (empty()) throw std::runtime_error("List is empty");

        Node* last = Tail->prev;
        value_type val = last->item;

        Node* prev = last->prev;
        prev->next = Tail;
        Tail->prev = prev;

        delete last;
        count--;
        return val;
    }

    void insert(iterator it, const value_type& r)
    {
        if (it.elem == nullptr) throw NullIterator();

        if (it == end())
        {
            push_back(r);
            return;
        }

        Node* el = it.elem;
        Node* next_el = el->next;

        Node* p = new Node(r);
        p->next = next_el;
        p->prev = el;

        el->next = p;
        if (next_el)
            next_el->prev = p;

        count++;
    }

    void erase(iterator it)
    {
        if (it == end()) throw std::runtime_error("Cannot erase end()");
        if (empty()) throw std::runtime_error("List is empty");

        Node* el = it.elem;
        Node* prev = el->prev;
        Node* next = el->next;

        if (prev) prev->next = next;
        if (next) next->prev = prev;

        delete el;
        count--;
    }

    void erase(iterator first, iterator last)
    {
        while (first != last)
        {
            iterator tmp = first;
            ++first;
            erase(tmp);
        }
    }

    void remove(const value_type& v)
    {
        iterator it = begin();
        while (it != end())
        {
            if (*it == v)
            {
                iterator tmp = it;
                ++it;
                erase(tmp);
            }
            else
            {
                ++it;
            }
        }
    }

    void swap(List& L)
    {
        std::swap(Head, L.Head);
        std::swap(Tail, L.Tail);
        std::swap(count, L.count);
    }

    void clear()
    {
        while (!empty())
            pop_front();
    }

    void splice(List& L)
    {
        splice(end(), L);
    }

    void splice(iterator it, List& L)
    {
        if (L.empty()) return;

        if (it == end())
        {
            while (!L.empty())
                push_back(L.pop_front());
        }
        else
        {
            Node* pos = it.elem;
            Node* next = pos->next;

            while (!L.empty())
            {
                Node* p = new Node(L.pop_front());
                p->prev = pos;
                p->next = next;

                pos->next = p;
                if (next) next->prev = p;

                pos = p;
                count++;
            }
        }
    }

    void sort()
    {
        if (count < 2) return;

        for (iterator i = begin(); i != end(); i++)
        {
            for (iterator j = begin(); j != end(); j++)
            {
                iterator k = j;
                ++k;
                if (k != end() && *j > *k)
                {
                    value_type tmp = *j;
                    *j = *k;
                    *k = tmp;
                }
            }
        }
    }

    void merge(List& L)
    {
        splice(L);
        sort();
    }

    // =============================
    // Friend I/O (СПОСІБ 2: всередині класу)
    friend std::ostream& operator<<(std::ostream& os, const List& l)
    {
        for (iterator it = l.begin(); it != l.end(); it++)
            os << *it << " ";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, List& l)
    {
        value_type x;
        is >> x;
        l.push_back(x);
        return is;
    }
};

// =============================
// Friend I/O (СПОСІБ 1: зовнішній шаблон)

template<class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l)
{
    for (typename List<T>::iterator it = l.begin(); it != l.end(); it++)
        os << *it << " ";
    return os;
}

template<class T>
std::istream& operator>>(std::istream& is, List<T>& l)
{
    T x;
    is >> x;
    l.push_back(x);
    return is;
}