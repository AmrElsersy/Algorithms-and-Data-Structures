#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> Stack;
    queue<int> Queue;

    int n ; cin >>n;
    for (int i =0 ; i < n ; i++)
    {
        string operation; int value = 0;
        cin >> operation ;
        if(operation == "PUSH")
        {
            cin >> value;
            Stack.push(value);
            Queue.push(value);
        }
        else if (operation == "POP")
        {
            Stack.pop();
            Queue.pop();
        }
    }


    int top ; cin >> top;

    bool isStack = (Stack.empty()) ? false : top == Stack.top() ;
    bool isQueue = (Queue.empty()) ? false : top == Queue.front() ;

    if (isStack && ! isQueue)
    {
        cout << "STACK" << endl;
    }
    else if ( ! isStack && isQueue)
    {
        cout << "QUEUE" << endl;
    }
    else
    {
        cout << "UNKNOWN" << endl;
    }

    return 0;
}
