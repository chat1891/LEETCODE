#include <unordered_map>

/// <summary>
/// use reverse trie to search from end to begin
/// </summary>
/// 
/*
Intuition
- construct a trie form each word from end to begin
- use reversed trie to search string from end to begin
- if find any return true, else false

Time: O(m*n): 
where N is a number of input words, and M is the word length

Space: O(m*n): 
In the worst-case newly inserted key doesn't share a prefix with the keys already added in the trie.
We have to add N*M new nodes,
*/
class TrieNode
{
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class StreamChecker
{
public:
    TrieNode* trieRoot;
    std::string ss;

    StreamChecker(std::vector<std::string>& words)
    {
        trieRoot = new TrieNode();
        for (auto& word : words)
        {
            TrieNode* node = trieRoot;
            //build a reverse trie
            for (int i = word.size() - 1; i >= 0; i--)
            {
                char& ch = word[i];
                if (node->children.count(ch) == 0)
                {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->isEnd = true;
        }
    }

    bool query(char letter)
    {
        ss += letter;
        TrieNode* node = trieRoot;
        for (int i = ss.length() - 1; i >= 0; i--)
        {
            char ch = ss[i];
            if (node->children.count(ch) == 0)
                return false;
            if (node->children[ch]->isEnd)
                return true;
            node = node->children[ch];
        }
        return node->isEnd;
    }
};
