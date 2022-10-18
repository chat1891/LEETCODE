#include <string>

//recursion

/*
Complexity Analysis
search:
Time complexity: 
O(M) for the "well-defined" words without dots, where M is the key length, and N is a number of keys, 
and O(N * 26^M). M for the "undefined" words. 
That corresponds to the worst-case situation of searching an undefined word {....} M times
which is one character longer than all inserted keys.


Space complexity: 
O(n)to keep the recursion stack.

*/
class TrieNode
{
public:
    TrieNode* children[26];
    bool isEnd = false;
};

class WordDictionary
{
public:
    TrieNode* root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(std::string word)
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

    bool helper(std::string& word, int pos, TrieNode* node)
    {
        //if(node==NULL) return false;
        if (pos == word.length()) return node->isEnd;
        char& ch = word[pos];

        // if there's not '.', we can just iterate in tree
        if (ch != '.')
        {
            return node->children[ch - 'a'] != NULL
                && helper(word, pos + 1, node->children[ch - 'a']);

        }
        // if there's a '.', we need to iterate in all possible cases
        for (int i = 0; i < 26; i++)
        {
            // 'node->children[i]' is here to avoid unnecessary recursion calls
            if (node->children[i] != NULL && helper(word, pos + 1, node->children[i]))
            {
                return true;
            }
        }

        return false;
    }

    bool search(std::string word)
    {
        TrieNode* node = root;
        return helper(word, 0, node);
    }
};