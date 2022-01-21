#include <bits/stdc++.h>
using namespace std;



class MyQueue {
    stack<int> s;
    stack<int> reverse_s;


    // transfer the elements from the stack to the other to reverse the order so we can use the new order as queue
    void transferStackToReverse()
    {
           // transfer the elements from the stack to the other to reverse the order
        if (!s.empty() && reverse_s.empty())
        {
            while (!s.empty())
            {
                int top = s.top();
                s.pop();
                reverse_s.push(top);
            }
        }
    }
public:
    MyQueue() {

    }

    void push(int x) {
        // transfer the elements back to the stack if it was already transfer by pop/peak operation
        if (s.empty() && !reverse_s.empty())
        {
            while (!reverse_s.empty())
            {
                int top = reverse_s.top();
                reverse_s.pop();
                s.push(top);
            }
        }

        s.push(x);
    }

    int pop() {
        // transfer the elements from the stack to the other to reverse the order
        this->transferStackToReverse();

        // pop the element from the reversed order & keep elements in the reversed stack
        // this is usufull when you call many pop() operations together so you dont need each time to copy elemnts from and to the 2 stacks
        // we will move elements again from reverse to original stack when it comes to push operation
        int queue_top = reverse_s.top();
        reverse_s.pop();
        return queue_top;
    }

    int peek() {
       // transfer the elements from the stack to the other to reverse the order
        this->transferStackToReverse();
        return reverse_s.top();
    }

    bool empty() {
        return s.empty() && reverse_s.empty();
    }
};

int main()
{
    auto d = new MyQueue();
    d->push(1);
    d->push(2);
    d->peek();
    d->pop();
    d->empty();
    return 0;
}
