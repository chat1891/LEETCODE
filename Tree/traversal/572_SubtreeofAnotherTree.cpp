
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Intuition:
for each node in root tree, check if it has subtree identical with subRoot, 
if not check left sub tree of root, and right sub tree of root, compare with subRoot

*/

// TIME O(M * N)
// M is number of nodes in root
// N is number of nodes in subRoot
/*
Space complexity: O(M+N).
There will be at most N recursive call to dfs ( or isSubtree). 
Now, each of these calls will have M recursive calls to isIdentical. 
Before calling isIdentical, our call stack has at most O(N) elements and might increase to O(N + M)during the call. 
After calling isIdentical, it will be back to at most O(N) since all elements made by isIdentical are popped out. 
Hence, the maximum number of elements in the call stack will be M+N.
*/
class Solution
{
public:
    bool checkSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;

        if (root && subRoot && root->val == subRoot->val)
        {
            bool l = checkSameTree(root->left, subRoot->left);
            bool r = checkSameTree(root->right, subRoot->right);
            return l && r;
        }
        return false;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        //can clarify in interview
        // null tree is a sub tree of a null tree
        //if subRoot is null, null tree is subTree of the other tree
        // leaf has null children
        if (!subRoot) return true;
        if (!root) return false;
        if (checkSameTree(root, subRoot))
            return true;
        //is subRoot the sub tree of root's left sub tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};