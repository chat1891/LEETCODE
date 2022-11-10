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

  //bfs
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == NULL) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};

//========================================
//dfs

/*
 Time: O(N)

Space complexity : in the worst case, the tree is completely unbalanced, 
e.g. each node has only left child node, the recursion call would occur N times (the height of the tree), 
therefore the storage to keep the call stack would be O(N)
But in the best case (the tree is completely balanced), the height of the tree would be log(N).
Therefore, the space complexity in this case would be O(log(N)).
*/
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == NULL) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};