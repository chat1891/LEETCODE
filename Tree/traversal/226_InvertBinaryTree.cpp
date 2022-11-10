
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  //dfs
class Solution
{
public:
    TreeNode* dfs(TreeNode* root)
    {
        if (root == nullptr)
            return root;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        dfs(root->left);
        dfs(root->right);

        return root;
    }
    TreeNode* invertTree(TreeNode* root)
    {
        return dfs(root);
    }
};