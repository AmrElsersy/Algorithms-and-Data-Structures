#include <iostream>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int key;

    Node()
    {
        left = nullptr;
        right = nullptr;
    }
};

#define MY_INT_MIN     (-2147483647 - 1) // minimum (signed) int value
#define MY_INT_MAX       2147483647    // maximum (signed) int value

bool findNode(Node *root, long long Min, long long Max)
{
    if (root == nullptr )
        return true;
    if (root->key < Min || root->key >= Max)
        return false;

    return findNode(root->left, Min, root->key) && findNode(root->right, root->key, Max);
}

int main()
{
    int n; cin >> n;

    if (n==0)
    {
        cout << "CORRECT" << endl;
        return 0;
    }

    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++)
        nodes[i] = new Node;

    // make the tree
    for (int i = 0; i < n; i++)
    {
        int key,left,right; cin >> key >> left >> right;
        nodes[i]->key = key;
        if (left != -1)
        {
            nodes[i]->left = nodes[left];
        }
        if (right != -1)
        {
            nodes[i]->right = nodes[right];
        }
    }



        if (!findNode(nodes[0],  LLONG_MIN, LLONG_MAX))
        {
            cout << "INCORRECT" << endl;
            return 0;
        }


    cout << "CORRECT" << endl;
    return 0;
}
