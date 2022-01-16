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

bool checkBinarySearchTree(Node *root, int minimum = INT_MIN, int maximum = INT_MAX)
{
    if (!root)
        return true;

    // if data is out of min/max range
    if (root->data < minimum || root->data > maximum)
        return false;

    // if left data not less than root or right data bigger than root
    if (root->left && root->left->data > root->data)
        return false;
    if (root->right && root->right->data < root->data)
        return false;

    // check BST to both left and right nodes but consider them the new root with the new ranges
    bool isLeftBST = checkBinarySearchTree(root->left, minimum, root->data);
    bool isRightBST = checkBinarySearchTree(root->right, root->data, maximum);

    // if all subtrees are BST then root is BST
    if (isLeftBST && isRightBST)
        return true;
    else
        return false;
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

    if (checkBinarySearchTree(root))
        cout << "BST" << endl;
    else
        cout << "Not BST";
    return 0;
}
*/
