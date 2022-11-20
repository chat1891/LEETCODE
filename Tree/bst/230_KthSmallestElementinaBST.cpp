#include <stack>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/// <summary>
/// recursive inorder traversal 
///  time O(n)
///  space O(n)
/// </summary>
class Solution
{
public:
    int res = 100000;
    void inorder(TreeNode* root, int& k)
    {
        if (root == nullptr)
            return;

        inorder(root->left, k);
        k--;
        if (k == 0)
            res = root->val;
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        inorder(root, k);
        return res;
    }
};

//================================
//iterative inorder
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::stack<TreeNode*> stk;
        while (true)
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            k--;
            if (k == 0)
                return root->val;
            root = root->right;
        }

    }
};