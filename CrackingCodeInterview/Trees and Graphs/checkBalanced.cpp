#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int _data)
    {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};

int TreeDepth(Node *root, int depth = 1)
{
    if (!root)
        return depth - 1;
    return max(TreeDepth(root->left, depth +1), TreeDepth(root->right, depth +1));
}
bool checkBalanced(Node *root)
{
    if (!root)
        return true;

    bool balanced = false;
    int l_depth = TreeDepth(root->left);
    int r_depth = TreeDepth(root->right);
    if (abs(l_depth - r_depth) <= 1)
        balanced = true;

    return balanced && checkBalanced(root->left) && checkBalanced(root->right);
}
/*
int main()
{
    /*
             5
           /  \
          3    20
         / \    /
        2   4  10
                \
                 15

    Node *root = new Node(5);
    Node *left = new Node(3);
    Node *left_left = new Node(2);
    Node *left_right = new Node(4);
    root->left = left;
    left->left = left_left;
    left->right = left_right;

    Node *right = new Node(20);
    Node *r_l = new Node(10);
    Node *r_r = new Node(15);
    root->right = right;
    right->left = r_l;
    r_l->right = r_r;

    cout << checkBalanced(root) << endl;
    return 0;
}

*/
