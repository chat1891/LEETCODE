#include <queue>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution
{
public:
    int maxDepth(Node* root)
    {
        if (root == NULL) return 0;
        std::queue<Node*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node* cur = q.front();
                q.pop();
                for (auto& child : cur->children)
                {
                    q.push(child);
                }
            }
            depth++;
        }
        return depth;
    }
};