#include <cstddef>
#include <vector>

/*
intuitive
- add each number to trie to construct a bitwise trie.
Every bit in a number has 2 possibilities : 0 & 1.
- for each number, starting from top, try to find opposite bit at each level to get maximum XOR result.
starting from top, can get a bigger number
- result is the max from all the numbers


Time complexity:
O(N)
It takes O(L) to insert a number in Trie, and O(L) to find the max XOR of the given number with all already inserted ones.
L = 1+ (log_2 M) is defined by the maximum number in the array 
and could be considered as a constant here Hence the overall time complexity is O(N)
M is 32, 32 bit
L is the height of the tree

Space complexity : 
O(1)
since one needs at maximum O(2^L)=O(M) space to keep Trie, 
and L and M could be considered as constants here because of input limitations

similar question:
1707. Maximum XOR With an Element From Array
*/


class TrieNode
{
public:
    TrieNode* children[2];
    bool isEnd = false;

    //add number to the trie
    void addNumber(TrieNode* root, int num)
    {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--)
        {
            int curBit = (num >> i) & 1;
            if (node->children[curBit] == NULL)
            {
                node->children[curBit] = new TrieNode();
            }
            node = node->children[curBit];
        }
    }
};

class Solution
{
public:
    void constructTrie(std::vector<int>& nums, TrieNode* root)
    {
        for (auto& num : nums)
        {
            root->addNumber(root, num);
        }
    }

    //at each trie level, choose the path has opposite bit
    int checkXOR(int num, TrieNode* root)
    {
        int res = 0;
        TrieNode* curNode = root;
        for (int i = 31; i >= 0; i--)
        {
            int curBit = (num >> i) & 1;
            int oppositeBit = curBit == 1 ? 0 : 1;
            //cannot find opposite bit, have to move to same as current bit
            if (curNode->children[oppositeBit] == NULL)
            {
                curNode = curNode->children[curBit];
            }
            else
            {
                //find opposite bit, add 1 to result
                res += (1 << i);
                curNode = curNode->children[oppositeBit];
            }
        }

        return res;
    }

    int findMaximumXOR(std::vector<int>& nums)
    {
        TrieNode* root = new TrieNode();
        constructTrie(nums, root);

        int ans = 0;
        //for each number, try to find maximum XOR
        for (auto& num : nums)
        {
            ans = std::max(ans, checkXOR(num, root));
        }

        return ans;

    }
};