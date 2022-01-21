#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
    stack<int> sorted;
    stack<int> buffer = s;

    while(sorted.size() < s.size())
    {
        int minimum = INT_MAX;
        while(!s.empty())
        {
            int x = s.top();
            s.pop();
            if (x < minimum)
                minimum = x;

            buffer.push(x);
        }
        while (!buffer.empty())
        {
            int top = buffer.top();
            buffer.pop();
            if (top != minimum)
                s.push(top);
        }
        sorted.push(minimum);
    }

    return sorted;
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(30);
    s.push(7);
    s.push(4);
    s.push(33);

    s = sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
