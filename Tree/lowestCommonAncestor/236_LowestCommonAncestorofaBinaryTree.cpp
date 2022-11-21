#include <unordered_set>
#include <queue>
#include <unordered_map>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursion
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == p->val)
            return root;
        if (root->val == q->val)
            return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if (l && r)
            return root;

        return l ? l : r;

    }
};

//==========================================
//iterative
/*
- find parent of each node and save in parentMap
- find ancestors of node p saved in p_parents set
- find ancestors of node q, if find match in p_parents set, it means it is the lowest common ancestor

Time: O(n)
Space O(n) for the queue
*/
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

//construct parentMap recursive way
void constructParentMap(TreeNode* parentNode, TreeNode* cur, std::unordered_map<TreeNode*, TreeNode*>& parentMap)
{
    if (cur == NULL)
    {
        return;
    }
    parentMap.insert({ cur,parentNode });

    constructParentMap(cur, cur->left, parentMap);
    constructParentMap(cur, cur->right, parentMap);

}
