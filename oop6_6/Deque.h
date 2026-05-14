#pragma once
#include "List.h"

template<class T>
class Deque
{
private:
    List<T> data;

public:
    typedef T value_type;

    bool empty() const { return data.empty(); }
    size_t size() const { return data.length(); }

    void push_front(const T& v) { data.push_front(v); }
    void push_back(const T& v) { data.push_back(v); }

    T pop_front() { return data.pop_front(); }
    T pop_back() { return data.pop_back(); }

    T& front() { return data.front(); }
    T& back() { return data.back(); }

    void clear() { data.clear(); }

    // Friend I/O (спосіб 2)
    friend std::ostream& operator<<(std::ostream& os, const Deque& d)
    {
        os << d.data;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Deque& d)
    {
        T x;
        is >> x;
        d.push_back(x);
        return is;
    }
};

// Friend I/O (спосіб 1)
template<class T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& d)
{
    os << d;
    return os;
}

template<class T>
std::istream& operator>>(std::istream& is, Deque<T>& d)
{
    T x;
    is >> x;
    d.push_back(x);
    return is;
}