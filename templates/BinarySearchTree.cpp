#include <stack>
#include <vector>

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//inorder traversal recursion
void inorder(std::vector<int>& nums, TreeNode* node)
{
    if (node == nullptr) return;
    inorder(nums, node->left);
    nums.push_back(node->val);
    inorder(nums, node->right);
}

//iterative inorder
//230. Kth Smallest Element in a BST
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::stack<TreeNode*> stk;
        while (true)
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            k--;
            if (k == 0)
                return root->val;
            root = root->right;
        }

    }
};

//====================================================
// LEETCODE 173. Binary Search Tree Iterator solution
//approach 2: inorder traversal using vector
//time O(n)
//space O(n)
class BSTIterator
{
public:
    TreeNode* root;
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

//==================================================
// LEETCODE 173. Binary Search Tree Iterator solution
//approach 3: inorder traversal using stack
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

//==================================================
// leetcode 653. Two Sum IV - Input is a BST
// bst iterator with space O(h)
class BSTiterator
{
private:
    std::stack<TreeNode*> stk;
    bool forward;
public:
    BSTiterator(TreeNode* root, bool forward)
    {
        this->forward = forward;
        if (forward) pushAllLeft(root);
        else pushAllRight(root);
    }

    void pushAllLeft(TreeNode* node)
    {
        while (node != NULL)
        {
            stk.push(node);
            node = node->left;
        }
    }

    void pushAllRight(TreeNode* node)
    {
        while (node != NULL)
        {
            stk.push(node);
            node = node->right;
        }
    }

    bool hasNext()
    {
        return !stk.empty();
    }

    int next()
    {
        TreeNode* node = stk.top();
        stk.pop();
        if (forward) pushAllLeft(node->right);
        else pushAllRight(node->left);
        return node->val;
    }

    int peek()
    {
        return stk.top()->val;
    }

};

class Solution
{
public:

    bool findTarget(TreeNode* root, int k)
    {
        //true means start with smallest element, from left to right
       // after using two pointer, left gets from smallest to biggest
        BSTiterator left = BSTiterator(root, true);
        //false means start with largest element, from right to left
        //top of the stack is the biggest, after using two pointer, right gets from biggest to smallest
        BSTiterator right = BSTiterator(root, false);

        while (left.hasNext() && right.hasNext())
        {
            int l = left.peek();
            int r = right.peek();

            if (l >= r) return false;
            if (l + r == k) return true;
            else if (l + r < k) left.next();
            else right.next();
        }

        return false;
    }
};