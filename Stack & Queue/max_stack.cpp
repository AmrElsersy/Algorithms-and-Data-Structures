#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> Stack;
    stack<int> Heap;

    int n ; cin >> n ;

    for(int i = 0 ; i < n; ++i)
    {
        string op; cin >> op;
        if (op == "push")
        {
            int x; cin >> x;
            Stack.push(x);
            if (Heap.size())
            {
                if (x >= Heap.top())
                    Heap.push(x);
            }
            else
                Heap.push(x);
        }
        else if (op == "pop")
        {
            int x = Stack.top();
            Stack.pop();

            if (x == Heap.top())
                Heap.pop();
        }
        else if (op == "max")
        {
            cout << Heap.top() << endl;
        }

    }

    return 0;
}
