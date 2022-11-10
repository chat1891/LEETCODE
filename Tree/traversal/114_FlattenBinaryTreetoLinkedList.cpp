
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
    TreeNode* flattenTree(TreeNode* node)
    {
        if (node == nullptr) return nullptr;
        if (node->left == nullptr && node->right == nullptr)
        {
            return node;
        }

        TreeNode* leftTail = flattenTree(node->left);

        TreeNode* rightTail = flattenTree(node->right);

        if (leftTail != nullptr)
        {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }

        return rightTail == nullptr ? leftTail : rightTail;
    }
    void flatten(TreeNode* root)
    {
        flattenTree(root);
    }
};