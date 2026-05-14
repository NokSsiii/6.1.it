#pragma once
#include <iostream>
#include <stdexcept>

template<class T, class Container>
class Queue
{
private:
    Container cont;

public:
    bool empty() const { return cont.empty(); }
    size_t size() const { return cont.size(); }

    void push(const T& x)
    {
        cont.push_back(x);
    }

    T pop()
    {
        return cont.pop_front();
    }

    T& front()
    {
        return cont.front();
    }

    T& back()
    {
        return cont.back();
    }

    void clear()
    {
        cont.clear();
    }

    // Friend I/O (спосіб 2)
    friend std::ostream& operator<<(std::ostream& os, const Queue& q)
    {
        os << q.cont;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Queue& q)
    {
        T x;
        is >> x;
        q.push(x);
        return is;
    }
};

// Friend I/O (спосіб 1)
template<class T, class Container>
std::ostream& operator<<(std::ostream& os, const Queue<T, Container>& q)
{
    os << q;
    return os;
}

template<class T, class Container>
std::istream& operator>>(std::istream& is, Queue<T, Container>& q)
{
    T x;
    is >> x;
    q.push(x);
    return is;
}