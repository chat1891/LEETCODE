#include <cstddef>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
* Algorithm:
- 1. Start traversing the tree from the root node.
    - If both the nodes p and q are in the right subtree, then continue the search with right subtree starting step 1.
    - If both the nodes p and q are in the left subtree, then continue the search with left subtree starting step 1.
    - If both step 2 and step 3 are not true, this means we have found the node which is common to node p's and q's subtrees. 
    and hence we return this common node as the LCA.

    Time:O(N)
    Space O(1)

*/

//iterative
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int pVal = p->val;
        int qVal = q->val;

        while (root)
        {
            if (pVal > root->val && qVal > root->val)
            {
                root = root->right;
            }
            else if (pVal < root->val && qVal < root->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return root;
    }
};

//recursive
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
    }
};