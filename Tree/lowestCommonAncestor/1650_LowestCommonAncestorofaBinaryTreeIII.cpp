#include <unordered_set>

// Definition for a Node.
class Node {
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
        std::unordered_set<Node*> pAncestors;
        while (p)
        {
            pAncestors.insert(p);
            p = p->parent;
        }

        while (q)
        {
            if (pAncestors.count(q) != 0)
            {
                return q;
            }
            q = q->parent;
        }

        return nullptr;
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