#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    Node *parent;

    int data;
    Node(int _data)
    {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};

// if node has right subtree, get the most left node of the right subtree
// else
//      if node is the left of its parent
//          parent is the next bigger node
//      if node is the right of its parent
//          traverse parents till get the bigger node
Node * nextBiggerNode(Node *node)
{
    // if it has right subtree get the most left
    if (node->right)
    {
        Node *mostLeft = node->right;
        while (mostLeft->left)
            mostLeft = mostLeft->left;

        return mostLeft;
    }
    else
    {
        if (node == node->parent->left)
            return node->parent;
        else if (node == node->parent->right)
        {
            Node *topParent = node->parent;

            // null checking is about if the node has no bigger value
            while (topParent && topParent->data < node->data)
                topParent = topParent->parent;

            return topParent;
        }
    }
}

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
    */
    Node *root = new Node(5);
    Node *left = new Node(3);
    Node *left_left = new Node(2);
    Node *left_right = new Node(4);

    root->left = left;  left->parent = root;
    left->left = left_left; left_left->parent = left;
    left->right = left_right; left_right->parent = left;

    Node *right = new Node(20);
    Node *r_l = new Node(10);
    Node *r_r = new Node(15);
    root->right = right;    right->parent = root;
    right->left = r_l;      r_l->parent = right;
    r_l->right = r_r;       r_r->parent = r_l;

    cout << nextBiggerNode(right)->data << endl;
    return 0;
}

