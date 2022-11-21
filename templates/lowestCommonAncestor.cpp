#include <cstddef>
#include <unordered_set>
#include <queue>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lca(TreeNode* root, int& startValue, int& destValue)
{
    if (root == nullptr)
        return nullptr;

    TreeNode* l = lca(root->left, startValue, destValue);
    TreeNode* r = lca(root->right, startValue, destValue);

    //this cannot be at line 19, before check left and right, because still want to check its left and right sub tree
    //if put at beginning, it will not check left and right
    //for example if q is at subtree of p, found p, it will not check its left and right subtree to find q, we will not know if q exists
    if (root->val == startValue)
        return root;
    if (root->val == destValue)
        return root;

    if (l && r)
        return root;
    return l ? l : r;
}

//=====================================
// iterative way
//236_Lowest Common Ancestor of a BinaryTree
class Solution
{
public:
    void constructParents(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& mp)
    {
        std::queue<TreeNode*> q;
        q.push(root);
        //add root to map
        mp[root] = nullptr;

        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left)
            {
                mp[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right)
            {
                mp[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }

    std::unordered_set<TreeNode*> findAncestors(TreeNode* node, std::unordered_map<TreeNode*, TreeNode*>& mp)
    {
        std::unordered_set<TreeNode*> ancestors;
        //add node itself to list
        ancestors.insert(node);

        while (true)
        {
            if (mp[node] == nullptr)
                break;
            ancestors.insert(mp[node]);
            node = mp[node];
        }
        return ancestors;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::unordered_map<TreeNode*, TreeNode*> mp;
        constructParents(root, mp);
        std::unordered_set<TreeNode*> pParents = findAncestors(p, mp);

        while (pParents.count(q) == 0)
        {
            q = mp[q];
        }
        return q;

    }
};

//================================


/*
 this solution uses the sum of the paths from the node till the root
 - assume distance of p to root=x  and q to root=y
 - the sum x+y will remain the same for both q and q. (path length from p to q)
 - distance is common(from lca to root): z

 - let a = p; travel from p to root (x), then let a = q, travel to lca (y-z): 
    x + (y-z)
 - let b = q; travel from q to root (y), then let b = p, travel to lca (x-z): 
    y + (x-z)

so that they reach x+y-z at the same time!
same idea as 160. Intersection of Two Linked Lists

Time: O(h1+h2)
    where h1 and h2 are the heights of nodes p and q
Space O(1)
*/


class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};


class Solution
{
public:
    Node* lowestCommonAncestor(Node* p, Node* q)
    {
        Node* a = p;
        Node* b = q;

        while (a != b)
        {
            if (a == nullptr)
            {
                //*here switch to use q not p as beginning 
                a = q;
            }
            else
            {
                a = a->parent;
            }

            if (b == nullptr)
            {
                //*here switch to use p not q as beginning
                b = p;
            }
            else
            {
                b = b->parent;
            }
        }

        return a;
    }
};