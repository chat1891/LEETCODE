#include <queue>

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 //iterative
//Time complexity : O(N)
//Space complexity : O(N)  in the worst case
//where the tree is a perfect fully balanced binary tree, 
//since BFS will have to store at least an entire level of the tree in the queue, and the last level has O(N) nodes
//height is h, max height = log (n)
//last level is 2^h = 2^(log(n)) = n

class Solution
{
public:

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        std::queue<TreeNode*> queue_p;
        std::queue<TreeNode*> queue_q;
        queue_p.push(p);
        queue_q.push(q);

        while (!queue_p.empty() && !queue_q.empty())
        {
            int szP = queue_p.size();
            int szQ = queue_q.size();
            if (szP != szQ) return false;

            for (int i = 0; i < szP; i++)
            {
                TreeNode* curP = queue_p.front();
                queue_p.pop();
                TreeNode* curQ = queue_q.front();
                queue_q.pop();

                //for[],[] do not break in null's left or right after
                if (curP == NULL && curQ == NULL) continue;
                if (curP == NULL || curQ == NULL) return false;
                if (curP->val != curQ->val) return false;

                queue_p.push(curP->left);
                queue_q.push(curQ->left);
                queue_p.push(curP->right);
                queue_q.push(curQ->right);

            }
        }
        return true;
    }
};

//recursion
//Time complexity : O(N)
//Space complexity : O(N)
class Solution_recursion
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;

        //if get to leaf without children.
        //will return isSameTree(p->left,q->left) is null and null = ture
        //and isSameTree(p->right,q->right) is also null and null = ture;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};