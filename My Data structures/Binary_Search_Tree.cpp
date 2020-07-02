#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MIN_INT 23312312
class Node
{
public:
    Node *left;
    Node *right;
    Node *parent;
    int key;

    Node(int _key)
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        key = _key;
    }
};

void print(Node *root)
{
    if (!root)
        return;
    cout << root->key << endl;
    print(root->left);
    cout << endl;
    print(root->right);
}

void Insert(Node *root, int key)
{
    if (!root)
        return ;
    else if (key >= root->key)
    {
        if (!root->right)
        {
            root->right = new Node(key);
            root->right->parent = root;
            return;
        }

        Insert(root->right, key);
    }
    else if (key < root->key)
    {
        if (!root->left)
        {
            root->left = new Node(key);
            root->left->parent = root;
            return;
        }

        Insert(root->left, key);
    }
}

Node *Find(Node *root, int key)
{
    if (!root)
        return nullptr;
    if (key == root->key)
        return root;
    else if (key > root->key)
        return Find(root->right, key);
    else if (key < root->key)
        return Find(root->left, key);
}

int getDepth(Node* it)
{
    if (! it)
        return 0;

    int l = getDepth(it->left);
    int r = getDepth(it->right);

    int depth = max(l,r);
    return ++depth;
}

int NextLeft(Node *root, int key)
{
    if (!root->parent)
        return MIN_INT;
    if (root->key > key)
        return root->key;
    return NextLeft(root->parent, key);
}
Node *NextRight(Node *root)
{
    if (!root->left)
        return root;
    return NextRight(root->left);
}

int FindNext(Node *root, int key)
{
    Node *node = Find(root, key);
    if (node->right)
        return NextRight(node->right)->key;
    else
        return NextLeft(node, key);
}

void Delete(Node *root, int key)
{
    Node *node = Find(root, key);
    if (node->left && !node->right)
    {
        node->left->parent = node->parent;
        if (node->parent->right == node)
            node->parent->right = node->left;
        else if (node->parent->left == node)
            node->parent->left = node->left;

        delete node;
    }
    else if (!node->left && node->right)
    {
        node->right->parent = node->parent;
        if (node->parent->right == node)
            node->parent->right = node->right;
        else if (node->parent->left == node)
            node->parent->left = node->right;

        delete node;
    }
    else if (node->left && node->right)
    {
        Node *deleted = NextRight(node->right);
        node->key = deleted->key;
        Delete(deleted, deleted->key);
    }
    else
    {
        // just delete it, it has no ahl ys2lo 3liha
        if (node->parent->right == node)
            node->parent->right = nullptr;
        else if (node->parent->left == node)
            node->parent->left = nullptr;
        delete node;
    }
}

Node *FindMin(Node *root)
{

}

int main()
{
    Node *root = new Node(5);
    int arr[] = {4,2,3,11,8,20,6, 10,15, 25,9};
    for (int i =0 ; i < 11; i++)
        Insert(root, arr[i]);

//    cout << FindNext(root, 20) << endl;
    Delete(root,11);

    print(root);
//    cout << getDepth(root) << endl;



    return 0;
}
