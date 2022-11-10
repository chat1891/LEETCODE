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

class Solution
{
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        int depth = 0;
        //node, parent
        std::queue<std::pair<TreeNode*, TreeNode*>> q;
        q.push({ root,nullptr });
        int depthx = -1;
        int depthy = -2;
        TreeNode* parentx;
        TreeNode* parenty;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto [cur, parent] = q.front();
                q.pop();
                if (cur->val == x)
                {
                    depthx = depth;
                    parentx = parent;
                }
                if (cur->val == y)
                {
                    depthy = depth;
                    parenty = parent;
                }
                if (cur->left)
                {
                    q.push({ cur->left,cur });

                }

                if (cur->right)
                {
                    q.push({ cur->right,cur });
                }
            }
            depth++;
        }

        if (depthx == depthy && parentx != parenty)
        {
            return true;
        }
        return false;
    }
};