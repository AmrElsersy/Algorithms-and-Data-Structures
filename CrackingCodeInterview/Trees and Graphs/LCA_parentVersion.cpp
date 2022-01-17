#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

int depth(TreeNode *root, int d = 0)
{
    if (!root)
        return d-1;
    return max(depth(root->left, d+1), depth(root->right, d+1));
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *topNode = depth(p) < depth(q) ? q : p;
    TreeNode *deepNode = topNode == q ? p : q;

    // difference in both depths
    int deltaDepth = abs(depth(p) - depth(q));
    // traverse parents with the diff of depths to make them close
    for (int i = 0 ; i < deltaDepth; i++)
            deepNode = deepNode->parent;

    // if deep node is a child of top node then top node is the LCA
    if (deepNode == topNode)
        return topNode;

    while (topNode != deepNode && topNode && deepNode)
    {
        deepNode = deepNode->parent;
        topNode = topNode->parent;
    }
    return topNode;
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

    Node5->parent = root;
    Node1->parent = root;
    Node6->parent = Node5;
    Node2->parent = Node5;
    Node7->parent = Node2;
    Node4->parent = Node2;
    Node0->parent = Node1;
    Node8->parent = Node1;

    auto LCA = lowestCommonAncestor(root, Node1, Node5);
    cout << LCA->val << endl;

    return 0;
}

