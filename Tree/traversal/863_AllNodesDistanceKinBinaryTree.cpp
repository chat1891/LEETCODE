#include <cstddef>
#include <unordered_map>
#include<unordered_set>
#include<vector>
#include <queue>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 //15min
 /*
 Logic:
 - use dfs to map node and its parent
 - init queue and visited set
 - from target, bfs go down and go up to one level
 - if left, right, parent not visited, add to queue
 - add everything in queue to result if get to the level
 */
class Solution
{
public:
    //add parent to hash map
    void dfs(std::unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* p, TreeNode* node)
    {
        parent[node] = p;
        if (node->left) dfs(parent, node, node->left);
        if (node->right) dfs(parent, node, node->right);
    }

    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        //use dfs to create map of node and its parent
        std::unordered_map<TreeNode*, TreeNode*> parent;
        dfs(parent, NULL, root);

        //init queue for bfs
        std::queue<TreeNode*> que;
        que.push(target);
        int distance = 0;
        std::vector<int> res;

        std::unordered_set<TreeNode*> visited;
        visited.insert(target);

        while (!que.empty())
        {
            if (distance == k)
            {
                //found distance, pop out everything from queue as result
                while (!que.empty())
                {
                    res.push_back(que.front()->val);
                    que.pop();
                }
                break;
            }
            int sz = que.size();

            //bfs each level
            for (int i = 0; i < sz; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                //if there is left child, and not visited, add to queue
                if (cur->left && visited.find(cur->left) == visited.end())
                {
                    visited.insert(cur->left);
                    que.push(cur->left);
                }
                //if there is right child, and not visited, add to queue
                if (cur->right && visited.find(cur->right) == visited.end())
                {
                    visited.insert(cur->right);
                    que.push(cur->right);
                }
                //if there is parent and parent is not visited
                if (parent[cur] != NULL && visited.find(parent[cur]) == visited.end())
                {
                    visited.insert(parent[cur]);
                    que.push(parent[cur]);
                }
            }
            distance++;
        }

        return res;
    }
};