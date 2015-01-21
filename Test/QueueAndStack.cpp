#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void QueueTest()
{
    queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
        cout << "push" << i << endl;
    }

    q.emplace(10);
    cout << q.size();

    for (int i = 0; i < 10; i++)
    {
        cout << "head: " << q.front() << "tail:  " << q.back() << endl;
        q.pop();
    }
    getchar();
}

void StackTest()
{
    stack<int> s;
    cout << "is empty?:" << s.empty() << endl;

    for (int i = 0; i < 10; i++)
    {
        s.push(i);
        cout << "push " << i << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "pop: " << s.top() << "size: " << s.size() << endl;
        s.pop();
    }
    getchar();
}