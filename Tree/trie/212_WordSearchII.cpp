#include <vector>
#include <string>
#include <unordered_set>

//using trie
//https://leetcode.com/problems/word-search-ii/discuss/1512202/C%2B%2B-or-TRIE%2BDFS-or-O(MN4(length_of_largest_word))-TIME-COMPLEXITY
class TrieNode
{
public:
    TrieNode* children[26];
    bool isEnd = false;
};

class Trie
{
public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(const std::string& word)
    {
        TrieNode* node = root;
        for (auto& ch : word)
        {
            int i = ch - 'a';
            if (node->children[i] == NULL)
            {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool startWith(const std::string& prefix)
    {
        TrieNode* node = root;
        for (auto& ch : prefix)
        {
            int nn = ch - 'a';
            if (node->children[ch - 'a'] == NULL) return false;
            node = node->children[ch - 'a'];
        }
        return true;
    }
};


class Solution
{
public:

    int nx, ny;
    std::vector<std::vector<int>> directions{ {0,1},{1,0},{-1,0},{0,-1} };
    std::unordered_set<std::string> res;
    std::vector<std::vector<bool>> visited;
    Trie* trie;

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

    void constructTrie(std::vector<std::string>& words)
    {
        for (auto& word : words)
        {
            trie->insert(word);
        }
    }

    void dfs(std::vector<std::vector<char>>& board, TrieNode* node, int x, int y, std::string s)
    {
        int cur = board[x][y] - 'a';
        //start with node->children, because start with root of trie which has nothing
        if (node->children[cur] == NULL) return;
        s += board[x][y]; //add before search

        //find leaf means find a word
        if (node->children[cur]->isEnd)
        {
            res.insert(s);
            node->children[cur]->isEnd = false;
            //if find one, do not return, keep searching next, because it might have more
        }

        //backtracking
        visited[x][y] = true;
        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            bool isValid = !(newx < 0 || newx >= nx || newy < 0 || newy >= ny);
            if (isValid && !visited[newx][newy])
            {
                dfs(board, node->children[cur], newx, newy, s);
            }

        }
        visited[x][y] = false;
    }

    void searchTrie(std::vector<std::vector<char>>& board)
    {
        //start with each letter in the board,
        //see if it can form a word
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                char c = board[i][j];
                //string startChar(1, c);
                //if(trie->startWith(startChar)){                                    
                TrieNode* node = trie->root;
                dfs(board, node, i, j, "");
                //}                
            }
        }
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, vector<string>& words)
    {
        nx = board.size();
        ny = board[0].size();
        visited = std::vector<std::vector<bool>>(nx, std::vector<bool>(ny, false));
        trie = new Trie();

        //add all the words to the trie
        constructTrie(words);
        searchTrie(board);

        std::vector<std::string> ans;
        for (auto& r : res)
        {
            ans.push_back(r);
        }
        return ans;

    }
};

//----===============================================================================
//backtracking
//time limit exceed
class Solution_2
{
public:
    int n, nx, ny;
    std::vector<std::vector<int>> directions{ {1,0},{-1,0},{0,1},{0,-1} };
    //vector<vector<int>> visited;
    bool isValid(const int& i, const int& j)
    {
        if (i < 0 || i >= nx || j < 0 || j >= ny) return false;
        return true;
    }

    bool dfs(std::vector<std::vector<char>>& board, std::string& word, int x, int y, int pos)
    {
        if (board[x][y] != word[pos])
            return false;
        if (pos == n - 1)
            return true;


        char prev = board[x][y];
        board[x][y] = '#';
        bool res = false;

        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            if (isValid(newx, newy))
            {
                res = res || dfs(board, word, newx, newy, pos + 1);
            }
        }
        board[x][y] = prev;

        return res;
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
    {
        nx = board.size();
        ny = board[0].size();
        std::vector<std::string> res;

        for (auto& word : words)
        {
            n = word.size();
            int pos = 0;
            if (n == 0) continue;
            bool found = false;

            for (int i = 0; i < nx && !found; i++)
            {
                for (int j = 0; j < ny && !found; j++)
                {
                    if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    {
                        res.push_back(word);
                        found = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};


//===================solution 3========
//use search method in trie template
//it checks every single combination of the string
//too slow, time limit exceeded

class TrieNode
{
public:
    TrieNode* children[26];
    bool isEnd = false;
};

class Trie
{
public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(const std::string& word)
    {
        TrieNode* node = root;
        for (auto& ch : word)
        {
            int i = ch - 'a';
            if (node->children[i] == NULL)
            {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(const std::string& word)
    {
        TrieNode* node = root;
        for (auto& ch : word)
        {
            int i = ch - 'a';
            if (node->children[i] == NULL)
            {
                return false;
            }
            node = node->children[i];
        }

        return node->isEnd;;
    }

    bool startWith(const std::string& prefix)
    {
        TrieNode* node = root;
        for (auto& ch : prefix)
        {
            if (node->children[ch - 'a'] == NULL) return false;
            node = node->children[ch - 'a'];
        }
        return true;
    }
};


class Solution_3
{
public:
    int nx, ny;
    std::vector<std::vector<int>> directions{ {0,1},{1,0},{-1,0},{0,-1} };
    std::unordered_set<std::string> res;
    std::vector<std::vector<bool>> visited;

    void constructTrie(Trie* t, std::vector<std::string>& words)
    {
        for (auto& word : words)
        {
            t->insert(word);
        }
    }

    void dfs(std::vector<std::vector<char>>& board, Trie* trie, int x, int y, std::string s)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return;
        if (visited[x][y]) return;
        //if(node == NULL) return;
        int cur = board[x][y] - 'a';
        s += board[x][y]; //add before search
        if (!trie->startWith(s))
        {
            return;
        }
        if (trie->search(s))
        {
            res.insert(s);
            //temp->is_word=false;
            //return;
        }

        visited[x][y] = true;
        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            dfs(board, trie, newx, newy, s);
        }
        visited[x][y] = false;

    }

    void searchTrie(std::vector<std::vector<char>>& board, Trie* trie)
    {
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                char& c = board[i][j];

                //TrieNode* node = trie->root;
                dfs(board, trie, i, j, "");

            }
        }
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, vector<string>& words)
    {
        //visited = std::vector<std::vector<bool>>(nx+1, std::vector<bool>(ny+1,false));
        nx = board.size();
        ny = board[0].size();
        visited = std::vector<std::vector<bool>>(nx, std::vector<bool>(ny, false));
        Trie* trie = new Trie();
        constructTrie(trie, words);

        searchTrie(board, trie);

        std::vector<std::string> ans;
        for (auto& r : res)
        {
            ans.push_back(r);
        }
        return ans;

    }
};


/*--------destructor not neccesary-----------
    ~Solution(){
        clear_nodes(root);
    }

    void clear_nodes(Trie* root) //
    {
        for(int i = 0; i<26; i++)
            if(root->children[i] != NULL)
                clear_nodes(root->children[i]);
        delete root;
    }
-------------------------------------------*/