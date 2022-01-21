class DinnerPlates {
public:
    vector<stack<int>> stacks;
    int capacity;
    DinnerPlates(int _capacity) {
        this->capacity = _capacity;
    }

    void push(int val) {
        if (stacks.size() == 0)
        {
            stack<int> s;
            stacks.push_back(s);
            stacks[0].push(val);
            return;
        }

        int index = 0;
        while (stacks[index].size() == capacity)
            index++;

        // if all stacks are full, add new stack
        if (index == stacks.size())
        {
            stack<int> s;
            stacks.push_back(s);
        }

        // push value to the left most not full stack
        stacks[index].push(val);
    }

    int pop()
    {
        if (stacks.size() == 0)
            return -1;

        int index = stacks.size() - 1;
        int val = stacks[index].top();
        stacks[index].pop();

        if (stacks[index].empty())
            stacks.pop_back();

        return val;
    }

    int popAtStack(int index) {
        int val = stacks[index].top();
        stacks[index].pop();
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
