#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool contain(TreeNode *root, TreeNode *node)
{
    if (!root || !node)
        return false;
    if (root == node)
        return true;

    return contain(root->left, node) || contain(root->right, node);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == q || root == p || !root)
        return root;

    bool pIsLeft = contain(root->left, p);
    bool qIsLeft = contain(root->left, q);

    // if p & q are in different branches (one on left and other on right) then the LCA is the root
    if (pIsLeft != qIsLeft)
    {
        return root;
    }
    // if they are in the same branch traverse down till find the LCA root
    // if both on left
    if (pIsLeft && qIsLeft)
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *Node0 = new TreeNode(0);
    TreeNode *Node1 = new TreeNode(1);
    TreeNode *Node2 = new TreeNode(2);
    TreeNode *Node4 = new TreeNode(4);
    TreeNode *Node5 = new TreeNode(5);
    TreeNode *Node6 = new TreeNode(6);
    TreeNode *Node7 = new TreeNode(7);
    TreeNode *Node8 = new TreeNode(8);

    root->left = Node5;
    root->right = Node1;
    Node5->left = Node6;
    Node5->right = Node2;
    Node2->left = Node7;
    Node2->right = Node4;
    Node1->left = Node0;
    Node1->right = Node8;

    auto LCA = lowestCommonAncestor(root, Node4, Node5);
    cout << LCA->val << endl;

    return 0;
}

