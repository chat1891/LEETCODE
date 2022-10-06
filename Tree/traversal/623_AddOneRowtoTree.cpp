#include<queue>

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {

        if (depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            newRoot->right = NULL;
            return newRoot;
        }

        std::queue<TreeNode*> que;
        que.push(root);
        int level = 1;
        while (level < depth - 1)
        {
            int curSize = que.size();

            for (int i = 0; i < curSize; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left != NULL)
                {
                    que.push(cur->left);
                }
                if (cur->right != NULL)
                {
                    que.push(cur->right);
                }
            }
            level++;

        }

        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();

            TreeNode* temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;

            temp = node->right;
            node->right = new TreeNode(val);
            node->right->right = temp;

        }

        return root;
    }
};