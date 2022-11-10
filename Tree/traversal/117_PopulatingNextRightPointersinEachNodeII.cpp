#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*

Time Complexity: O(N) since we process each node exactly once. 
Note that processing a node in this context means popping the node from the queue 
and then establishing the next pointers.

Space Complexity: O(N). 
This is a perfect binary tree which means the last level contains N/2 nodes. 
The space complexity for breadth first traversal is the maximum space occupied and the space occupied by the queue 
is dependent upon the maximum number of nodes in particular level. 
So, in this case, the space complexity would be O(N).
*/

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (root == nullptr) return nullptr;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node* cur = q.front();
                q.pop();

                if (i != sz - 1)
                {
                    cur->next = q.front();

                }
                else
                {
                    cur->next = nullptr;
                }

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};