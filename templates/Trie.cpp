#include <string>

class TrieNode
{
public:
    // each node has 26 children, from a to z
    TrieNode* children[26];
    bool isEnd = false;
    //TrieNode()
    //{
    //    for (int i = 0; i < 26; i++)
    //    {
    //        children[i] = NULL;
    //    }
    //}
};

class Trie
{

public:

    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string word)
    {
        TrieNode* node = root;

        for (auto& c : word)
        {
            int i = c - 'a';
            if (node->children[i] == NULL)
            {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(std::string word)
    {
        TrieNode* node = root;
        for (auto& c : word)
        {
            int i = c - 'a';
            if (node->children[i])
            {
                node = node->children[i];
            }
            else
            {
                return false;
            }
        }
        return node->isEnd;
    }

    bool startsWith(std::string prefix)
    {
        TrieNode* node = root;
        for (auto& c : prefix)
        {
            int i = c - 'a';
            if (node->children[i] == NULL)
            {
                return false;
            }
            node = node->children[i];
        }
        return true;
    }
};


class Solution
{
public:
    Trie* trie;
    Solution()
    {
        trie = new Trie();
    }

    //***=========================== deconstructor to free the memory
    ~Solution()
    {
        clear_nodes(trie->root);
        delete trie;
    }

    void clear_nodes(TrieNode* root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i] != NULL)
                clear_nodes(root->children[i]);
        delete root;
    }
    //***=========================== deconstructor to free the memory
};