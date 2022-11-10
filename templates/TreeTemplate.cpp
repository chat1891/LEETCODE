#include <vector>
#include <queue>
 struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

 //bfs, iterative
 class Solution
 {
 public:
     std::vector<std::vector<int>> levelOrder(TreeNode* root)
     {
         std::vector<std::vector<int>> res;
         if (root == nullptr) return res;
         std::queue<TreeNode*> q;
         q.push(root);
         while (!q.empty())
         {
             int sz = q.size();
             std::vector<int> level;
             for (int i = 0; i < sz; i++)
             {
                 TreeNode* cur = q.front();
                 q.pop();
                 level.push_back(cur->val);

                 if (cur->left)
                 {
                     q.push(cur->left);
                 }

                 if (cur->right)
                 {
                     q.push(cur->right);
                 }
             }
             res.push_back(level);
         }
         return res;
     }
 };

 //bfs, recursion
 class Solution
 {
 public:
     void dfs(TreeNode* node, int level, std::vector<std::vector<int>>& res)
     {
         if (node == nullptr)
         {
             return;
         }
         if (res.size() == level)
         {
             res.push_back(std::vector<int>());
         }
         res[level].push_back(node->val);
         dfs(node->left, level + 1, res);
         dfs(node->right, level + 1, res);
     }

     std::vector<std::vector<int>> levelOrder(TreeNode* root)
     {
         std::vector<std::vector<int>> res;
         if (root == nullptr) return res;
         dfs(root, 0, res);

         return res;
     }
 };