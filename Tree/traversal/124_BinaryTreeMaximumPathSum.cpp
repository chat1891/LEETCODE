#include <climits>
#include <algorithm>

// Definition for a binary tree node.
/*
Time O(N)

Space: Average is O(LOG N), LOG N is height
worst case is O(N) for stack
*/
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
    int maxVal = INT_MIN;

    int dfs(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        //if negative, takes 0;
        int left = std::max(dfs(node->left), 0);
        int right = std::max(dfs(node->right), 0);
        //split here
        //can only split once
        maxVal = std::max(maxVal, left + right + node->val);

        //because value checked before for splitting
        //all the return shouldn't split
        //can only split once
        //cannot go back again
        //so the node can only take either left or right
        //9->-10->20->15
        //9->-10->20->7
        //cannot be 9->-10->20->15->20->7
        return std::max(left, right) + node->val;
    }
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return maxVal;
    }
};