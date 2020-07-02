#include <iostream>
#include <bits/stdc++.h>
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

void inOrder(Node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->key << " " ;
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->key << " " ;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " " ;
}


int main()
{
    int n; cin >> n;

    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++)
        nodes[i] = new Node;

    // make the tree
    for (int i = 0; i < n; i++)
    {
        int key,left,right; cin >> key >> left >> right;
        nodes[i]->key = key;
        if (left != -1)
            nodes[i]->left = nodes[left];
        if (right != -1)
            nodes[i]->right = nodes[right];
    }

    inOrder(nodes[0]);
    cout << endl;
    preOrder(nodes[0]);
    cout << endl;
    postOrder(nodes[0]);

    return 0;
}
