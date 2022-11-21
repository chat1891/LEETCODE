#include <cstddef>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int count = 0;
    TreeNode* solveLCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL) return root;

        TreeNode* left = solveLCA(root->left, p, q);
        TreeNode* right = solveLCA(root->right, p, q);

        //this cannot be at line 14, because still want to check its left and right sub tree
        //if put at beginning, it will not check left and right
        if (root == p || root == q)
        {
            count++;
            return root;
        }


        //if find p and q in left and right tree, that means this root is LCA
        if (left != NULL && right != NULL)
        {
            return root;
        }
        else if (left != NULL)
        {
            //if right is null, means it is not in right
            return left;
        }
        else if (right != NULL)
        {
            return right;
        }
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        count = 0;
        TreeNode* res = solveLCA(root, p, q);
        if (count == 2)
        {
            return res;
        }
        return NULL;
    }
};