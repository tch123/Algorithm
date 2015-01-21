#include<stack>
#include<iostream>
#include<list>

using namespace std;

int main()
{
    const int N = 50;
    const int M = 7;
    list<int> l;
    for (int i = 0; i < N; i += 1)
    {
        l.push_back(i);
    }

    for each (auto var in l)
    {
        cout << var << "->";
    }
    getchar();


    list<int>::iterator cur = begin(l);
    for (int i = 0; i < N - 1; i++)
    {
        
    }

}