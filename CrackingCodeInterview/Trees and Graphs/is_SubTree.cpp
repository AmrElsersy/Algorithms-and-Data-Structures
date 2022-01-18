#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isIdenticalSubTrees(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    if (root1->val != root2->val)
        return false;
    return isIdenticalSubTrees(root1->left, root2->left) && isIdenticalSubTrees(root1->right, root2->right);
}

void candidateSubTrees(TreeNode *root, int valSubTree, vector<TreeNode *> &candidates)
{
    if (!root)
        return;
    if (root->val == valSubTree)
        candidates.push_back(root);

    candidateSubTrees(root->left, valSubTree, candidates);
    candidateSubTrees(root->right, valSubTree, candidates);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    vector<TreeNode *> candidates;
    candidateSubTrees(root, subRoot->val, candidates);
    for (auto node : candidates)
    {
        if (isIdenticalSubTrees(node, subRoot))
            return true;
    }
    return false;
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

    cout << isSubtree(root, Node4) << endl;
    return 0;
}

