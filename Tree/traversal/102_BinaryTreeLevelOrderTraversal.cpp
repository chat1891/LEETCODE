#include <vector>
#include <queue>
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 class Solution_bfs
 {
 public:
     std::vector<std::vector<int>> levelOrder(TreeNode* root)
     {
         std::vector<std::vector<int>> res;
         if (root == NULL) return res;
         std::queue<TreeNode*> que;
         que.push(root);

         while (!que.empty())
         {
             int sz = que.size();
             std::vector<int> level;
             while (sz--)
             {
                 TreeNode* cur = que.front();
                 level.push_back(cur->val);
                 que.pop();
                 if (cur->left) que.push(cur->left);
                 if (cur->right) que.push(cur->right);
             }
             res.push_back(level);
         }
         return res;
     }

 };

class Solution_dfs
{
    //there are two ways to do it
    //recursion vs iterative
    //102. Binary Tree Level Order Traversal
public:
    void dfs(TreeNode* node, int level, std::vector<std::vector<int>>& res)
    {
        if (node == NULL) return;
        if (res.size() == level) res.push_back(std::vector<int>());

        res[level].push_back(node->val);
        dfs(node->left, level + 1, res);
        dfs(node->right, level + 1, res);

    }
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        dfs(root, 0, res);

        return res;
    }
};