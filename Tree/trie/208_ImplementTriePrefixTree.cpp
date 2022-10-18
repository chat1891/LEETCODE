#include <string>

class TrieNode
{
public:
    //std::vector<TrieNode*> children;
    TrieNode* children[26];
    bool isEnd = false;
    // TrieNode()
    // {
    //     //children = std::vector<TrieNode*>(26);
    //     for(int i=0; i<26; i++)
    //     {
    //         children[i] = NULL;
    //     }        
    // }
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
            if (node->children[i])
            {
                node = node->children[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};