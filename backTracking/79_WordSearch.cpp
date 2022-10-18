#include<vector>
#include<string>
class Solution
{
public:
    std::vector<std::vector<int>> directions{ {0,1},{1,0},{-1,0},{0,-1} };
    int n, nx, ny;

    bool isValid(const int& i, const int& j)
    {
        if (i < 0 || i >= nx || j < 0 || j >= ny) return false;
        return true;
    }

    bool dfs(std::vector<std::vector<char>>& board, std::string& s, int x, int y, int pos)
    {
        if (board[x][y] != s[pos]) return false;
        if (pos == n - 1)
        {
            return true;
        }

        bool res = false;

        char prev = board[x][y];
        //change to '#' to mark as visited
        board[x][y] = '#';
        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            if (isValid(newx, newy))
            {
                res = res || dfs(board, s, newx, newy, pos + 1);
            }
        }
        board[x][y] = prev;
        return res;

    }

    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        n = word.length();
        if (n == 0) return false;

        ny = board[0].size();
        nx = board.size();

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


class Solution
{
public:
    std::vector<std::vector<int>> directions{ {0,1},{1,0},{-1,0},{0,-1} };
    int n, nx, ny;
    std::vector<std::vector<bool>> visited;

    bool isValid(const int& i, const int& j)
    {
        if (i < 0 || i >= nx || j < 0 || j >= ny) return false;
        return true;
    }

    bool dfs(std::vector<std::vector<char>>& board, std::string& s, int x, int y, int pos)
    {
        if (board[x][y] != s[pos]) return false;
        if (pos == n - 1)
        {
            return true;
        }

        bool res = false;
        visited[x][y] = true;
        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            if (isValid(newx, newy) && (!visited[newx][newy]))
            {
                res = res || dfs(board, s, newx, newy, pos + 1);
            }
        }
        visited[x][y] = false;
        return res;

    }

    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        n = word.length();
        if (n == 0) return false;

        ny = board[0].size();
        nx = board.size();
        //use visited set
        visited = std::vector<std::vector<bool>>(nx, std::vector<bool>(ny, false));

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};