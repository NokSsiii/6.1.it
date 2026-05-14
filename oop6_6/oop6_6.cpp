#include <iostream>
#include <string>
#include "List.h"
#include "Deque.h"
#include "Queue.h"

using namespace std;

int main()
{
    // 1 екземпляр: Queue<int, Deque<int>>
    Queue<int, Deque<int>> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);

    cout << "q1: " << q1 << endl;
    cout << "front: " << q1.front() << endl;
    cout << "back: " << q1.back() << endl;
    cout << "size: " << q1.size() << endl;

    cout << "pop: " << q1.pop() << endl;
    cout << "q1 after pop: " << q1 << endl;

    // 2 екземпляр: Queue<string, List<string>>
    Queue<string, List<string>> q2;
    q2.push("Hello");
    q2.push("World");

    cout << "\nq2: " << q2 << endl;
    cout << "front: " << q2.front() << endl;
    cout << "back: " << q2.back() << endl;
    cout << "size: " << q2.size() << endl;

    cout << "pop: " << q2.pop() << endl;
    cout << "q2 after pop: " << q2 << endl;

    q2.clear();
    cout << "q2 empty after clear: " << q2.empty() << endl;

    return 0;
}