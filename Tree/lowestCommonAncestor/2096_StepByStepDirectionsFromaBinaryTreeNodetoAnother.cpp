#include <string>

 //Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
- Build directions for both start and destination from the root (lowest common ancestor).
- Replace all steps from root to start direction to "U" 
- reverse steps from root to destination, because it adds last step first

*/
class Solution
{
public:
    TreeNode* lca(TreeNode* root, int& startValue, int& destValue)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == startValue)
            return root;
        if (root->val == destValue)
            return root;

        TreeNode* l = lca(root->left, startValue, destValue);
        TreeNode* r = lca(root->right, startValue, destValue);

        if (l && r)
            return root;
        return l ? l : r;
    }

    bool findPath(TreeNode* root, int& target, std::string& path)
    {
        if (!root)
            return false;
        if (root->val == target)
            return true;

        if (findPath(root->left, target, path))
        {
            path += 'L';
        }
        else if (findPath(root->right, target, path))
        {
            path += 'R';
        }

        return path != "";
    }

    std::string getDirections(TreeNode* root, int startValue, int destValue)
    {
        TreeNode* Lca = lca(root, startValue, destValue);

        std::string startPath = "";
        findPath(Lca, startValue, startPath);
        for (auto& c : startPath) c = 'U';

        std::string destPath = "";
        findPath(Lca, destValue, destPath);
        reverse(destPath.begin(), destPath.end());

        return startPath + destPath;

    }
};