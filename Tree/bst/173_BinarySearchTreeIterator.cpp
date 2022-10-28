#include <stack>
#include <vector>
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  //time O(n)
  //space O(h)
class BSTIterator
{
public:
    std::stack<TreeNode*> stk;
    void pushAllLeft(TreeNode* root)
    {
        while (root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root)
    {
        pushAllLeft(root);
    }

    int next()
    {
        TreeNode* node = stk.top();
        stk.pop();
        pushAllLeft(node->right);
        return node->val;

    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

//approach 2: inorder traversal using vector
//time O(n)
//space O(n)
class BSTIterator
{
public:
    TreeNode* root;
    std::vector<TreeNode*> stk;
    std::vector<TreeNode*> nodes;
    int idx;
    BSTIterator(TreeNode* root)
    {
        this->root = root;
        idx = 0;
        inorder(root);
    }

    void inorder(TreeNode* root)
    {
        if (root == NULL) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    int next()
    {

        if (idx < nodes.size())
        {
            return nodes[idx++]->val;
        }

        return -1;

    }

    bool hasNext()
    {
        return idx < nodes.size();
    }
};