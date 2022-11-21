#include <cstddef>
#include <unordered_set>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* lca(TreeNode* root, std::unordered_set<TreeNode*>& nodeSet)
    {
        if (root == NULL)
            return NULL;

        TreeNode* l = lca(root->left, nodeSet);
        TreeNode* r = lca(root->right, nodeSet);

        if (nodeSet.find(root) != nodeSet.end())
        {
            return root;
        }

        if (l && r)
            return root;
        return l ? l : r;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, std::vector<TreeNode*>& nodes)
    {
        std::unordered_set<TreeNode*> nodeSet;
        for (auto n : nodes)
        {
            nodeSet.insert(n);
        }

        return lca(root, nodeSet);

    }
};