class MinStack {
public:
    stack<int> s;
    stack<int> minStack;
    int minimum = INT_MAX;

    MinStack() {
    }

    void push(int val) {
        s.push(val);
        if (minStack.empty())
            minimum = val;
        else if (val < minStack.top())
            minimum = val;
        else
            minimum = minStack.top();

        minStack.push(minimum);
    }

    void pop() {
        s.pop();
        minStack.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};
