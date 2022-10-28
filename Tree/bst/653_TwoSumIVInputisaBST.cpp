#include <queue>
#include <unordered_set>
#include <stack>
//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//Similar problem :
//173. Binary Search Tree Iterator

//Approach 1 Controlled Recursion: use stack to simulate inorder traversal
//time O(n)
//space O(h)
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
         BSTiterator left = BSTiterator(root, true);
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

 //==================================================
 //Approach 2
 //time O(n)
//space O(n)
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

//====================================================================
//approach 3: inorder traversal then use two pointers
//time O(n)
//space O(n)
class Solution
{
public:
    void inorder(std::vector<int>& nums, TreeNode* node)
    {
        if (node == nullptr) return;
        inorder(nums, node->left);
        nums.push_back(node->val);
        inorder(nums, node->right);
    }

    bool findTarget(TreeNode* root, int k)
    {
        std::vector<int> inorderNums;
        inorder(inorderNums, root);
        int left = 0;
        int right = inorderNums.size() - 1;
        while (left < right)
        {
            if (inorderNums[left] + inorderNums[right] < k)
            {
                left++;
            }
            else if (inorderNums[left] + inorderNums[right] > k)
            {
                right--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};