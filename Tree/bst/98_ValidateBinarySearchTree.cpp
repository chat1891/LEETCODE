#include <climits>

/*
Binary search tree, root is bigger than every node in left subtree
root is smaller than every node in right subtree

- set left and right boundary, -infinity < root < +infinity
- move to left update its right boundary, because left < root
- move to right update its left boundary, because right > root

Time: O(2 n), every node makes one or two comparison
Space O(n)
*/

// Definition for a binary tree node.
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
    bool inorder(TreeNode* root, long left, long right)
    {
        if (root == nullptr)
            return true;

        if (!(root->val > left && root->val < right))
        {
            return false;
        }
        //going left update right boundary
        //left < node
        bool l = inorder(root->left, left, root->val);

        //going right update right boundary
        //right > node
        bool r = inorder(root->right, root->val, right);

        return l && r;
    }

    bool isValidBST(TreeNode* root)
    {
        return inorder(root, LONG_MIN, LONG_MAX);
    }
};


//=============================
class Solution
{
public:
    long prev = LONG_MIN;

    bool inorderRecursion(TreeNode* root)
    {
        if (root == NULL) return true;

        //inorder to visit left
        bool left = inorderRecursion(root->left);
        if (!left) return false;

        if (prev >= root->val) return false;
        //inorder to visit parent
        prev = root->val;

        //inorder to visit right
        return inorderRecursion(root->right);
    }

    bool isValidBST(TreeNode* root)
    {

        return inorderRecursion(root);
    }
};