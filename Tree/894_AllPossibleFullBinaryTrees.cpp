#include <string>
using namespace std;
#include <tuple>
#include <algorithm> 
#include <queue>
#include <unordered_map>

/*
* https://leetcode.com/problems/all-possible-full-binary-trees/discuss/2534430/Simple-C%2B%2B-Solution-implemented-using-Recursion-and-Memoization
Intuition / Approach
A full binary tree is a special type of binary tree in which every node has either two or zero children, 
which implies that the total numbers of node in a full binary tree must be odd.This gives us our first base case for the recursive solution : 
if 'n' is even(i.e.n % 2 == 0), then number of possible full binary trees is 0. So, we return a empty vector.

The second base case is a simple one : if n is 1, then only one full binary tree is possible, which is root itself, 
hence we return a vector with one node(i.e{ new TreeNode(0) })

Now, its time to find the recurrence relation(i.e.we need to find the relationship between the problem and it's subproblems). 
Take a loot at the figure below, where F(n) represents a full binary tree having n nodes.
*/

/*
We can observe that:

For n = 7, the left subtree (lst) has either 1 or 3 nodes and right subtree (rst) has either 5 or 3 nodes, respectively.
If we try to generalize for n, then F(n) = 1 + F(i) + F(n - i - 1), where the term 1 is for the root, F(i) is for lst and F(n-i-1) is for rst.
We can also observe that F(3) and F(5) has more than one configuration, and we need to consider all possible configurations.
And since there are overlapping subproblems, we can store the results to avoid recomputation.
How to calculate all possible configurations?
Loop with i = 1 to n, and increment with step of 2 (i.e. i += 2), because we only need to consider trees where n is odd. (explained above)
Then, for each iteration:
Calculate the result for both subtrees and store them.
For every lnode in lst, select a rnode from the rst, and create a new node having val = 0, left child as lnode and right child as rnode.
Push this new node as the root of a possible full binary tree.
And that's it
Note: We are using a hash table for storing the results of each function call, unordered_map is the abstract data structure for a hash table in C++. It provides constant time operations like insertion, search and delete capabilities on an average case.
*/

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution
{
public:
    unordered_map<int, vector<TreeNode*>> subTrees;
    //vector<TreeNode*> res;

    vector<TreeNode*> dfs(int n)
    {
        vector<TreeNode*> ans;

        if (n <= 0 || n % 2 == 0)
            return ans;
        else if (subTrees.find(n) != subTrees.end())
        {
            return subTrees[n];
        }
        else if (n == 1)
        {
            TreeNode* node = new TreeNode(0);
            ans.push_back(node);
            subTrees.insert({ 1,ans });
            //return {new TreeNode(0)};
        }

        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode*> leftSubTrees = dfs(i);
            vector<TreeNode*> rightSubTrees = dfs(n - i - 1);

            for (int l = 0; l < leftSubTrees.size(); l++)
            {
                for (int r = 0; r < rightSubTrees.size(); r++)
                {
                    TreeNode* cur = new TreeNode(0);
                    cur->left = leftSubTrees[l];
                    cur->right = rightSubTrees[r];
                    ans.push_back(cur);
                }
            }
        }

        subTrees[n] = ans;
        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n)
    {
        return dfs(n);
    }
};

class Solution_cleanWayOfWriting
{
    unordered_map<int, vector<TreeNode*>> mp;
public:
    vector<TreeNode*> allPossibleFBT(int n)
    {
        vector<TreeNode*> result;

        if (n % 2 == 0) return {};
        if (n == 1) return { new TreeNode(0) };
        if (mp.find(n) != mp.end()) return mp[n];


        for (int i = 1; i < n; i += 2)
        {
            auto lst = allPossibleFBT(i);
            auto rst = allPossibleFBT(n - i - 1);

            for (auto lnode : lst)
            {
                for (auto rnode : rst)
                {
                    result.push_back(new TreeNode(0, lnode, rnode));
                }
            }
        }

        return mp[n] = result;
    }
};