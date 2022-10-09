#include <queue>
#include <unordered_set>
//Definition for a binary tree node.
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
    bool findTarget(TreeNode* root, int k)
    {
        std::unordered_set<int> mp;
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            int val2 = k - cur->val;
            if (mp.find(val2) != mp.end())
            {
                return true;
            }
            mp.insert(cur->val);

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }

        return false;
    }
};