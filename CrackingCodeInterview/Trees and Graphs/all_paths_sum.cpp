/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void sumAllPaths(TreeNode *root, int currentSum, map<int, vector<TreeNode*>> &sumAtNodes)
{
    if (!root)
        return;

    int newSum = currentSum + root->val;

    if (!sumAtNodes.count(newSum))
        sumAtNodes[newSum] = vector<TreeNode*>();
    sumAtNodes[newSum].push_back(root);

    if (root->left)
        sumAllPaths(root->left, newSum, sumAtNodes);
    if (root->right)
        sumAllPaths(root->right, newSum, sumAtNodes);
}

bool isChild(TreeNode *root, TreeNode *node)
{
    if (!root)
        return false;
    if (root->left && root->left == node)
        return true;
    if (root->right && root->right == node)
        return true;

    return isChild(root->left, node) || isChild(root->right, node);
}

int pathSum2(TreeNode* root, int targetSum)
{
    int paths = 0;

    map<int, vector<TreeNode*>> sumAtNodes;
    sumAllPaths(root, 0, sumAtNodes);

    for (auto it = sumAtNodes.begin(); it != sumAtNodes.end(); it++)
    {
        for (auto i : it->second)
            cout << "Node " << i->val << "  ";
            cout <<  "sum = " << it->first << endl;

        int requiredSum = it->first - targetSum;
        if (requiredSum == 0)
        {
            paths += it->second.size();
        }

        if (sumAtNodes.count(requiredSum))
        {
            vector<TreeNode *> childs = it->second;
            vector<TreeNode *> parents  = sumAtNodes[requiredSum];

            for (auto parent : parents)
            {
                for (auto child : childs)
                {
                    if (isChild(parent, child))
                        paths++;
                }
            }
        }
    }
    return paths;
}

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        return pathSum2(root, targetSum);
    }
};
