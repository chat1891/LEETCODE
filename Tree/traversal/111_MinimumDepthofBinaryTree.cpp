#include <cstddef>
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

 //this is faster, runtime beats 98%
 class Solution
 {
 public:
     int minDepth(TreeNode* root)
     {
         if (root == NULL) return 0;

         std::queue<std::pair<TreeNode*, int>> que; //node, depth
         que.push({ root,1 });
         int h = INT_MAX;

         while (!que.empty())
         {
             auto& [node, depth] = que.front();
             if (node->left == NULL && node->right == NULL)
             {
                 return depth;
             }
             if (node->left != NULL)
             {
                 que.push({ node->left,depth + 1 });
             }
             if (node->right != NULL)
             {
                 que.push({ node->right,depth + 1 });
             }

             que.pop();
         }

         return h;
     }
 };

 //this is slow 
class Solution_regularTemp
{
public:
    int minDepth(TreeNode* root)
    {
        if (root == NULL) return 0;

        std::queue<TreeNode*> que;
        que.push(root);
        int depth = 1;

        while (!que.empty())
        {
            int sz = que.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if (node->left == NULL && node->right == NULL)
                {
                    return depth;
                }
                if (node->left != NULL)
                {
                    que.push(node->left);
                }
                if (node->right != NULL)
                {
                    que.push(node->right);
                }
            }
            depth++;

        }

        return depth;
    }
};