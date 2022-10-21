#include <vector>
#include<queue>
#include <stack>

//can use union find


/*
approach 1 use bfs
- loop through each cell, 
- when find a '1', add to queue, for each item go through every valid direction
if find '1' add to queue, change value to '0', so we dont visit again
-when queue is empty, means we find a island


Time complexity : O(M×N) where M is the number of rows and NN is the number of columns.
Space complexity :O(min(M,N)) because in worst case where the grid is filled with lands, the size of queue can grow up to min(M,N).

*/
class Solution
{
public:
    std::vector<std::vector<int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
    int nx;
    int ny;

    bool isValid(int& x, int& y)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return false;
        return true;
    }

    void bfs(int i, int j, std::vector<std::vector<char>>& grid)
    {
        std::queue<std::pair<int, int>> que;
        que.push({ i,j });
        grid[i][j] = '0';
        while (!que.empty())
        {
            auto& [x, y] = que.front();

            for (auto& dir : directions)
            {
                int newx = x + dir[0];
                int newy = y + dir[1];
                if (isValid(newx, newy))
                {
                    if (grid[newx][newy] == '1')
                    {
                        que.push({ newx,newy });
                        grid[newx][newy] = '0';
                    }
                }
            }

            que.pop();
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        nx = grid.size();
        ny = grid[0].size();
        int res = 0;

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    bfs(i, j, grid);
                }
            }
        }
        return res;
    }
};


//approach 2 dfs recursive

/*
Time complexity : O(M×N) where M is the number of rows and N is the number of columns.
Space complexity : worst case O(M×N) in case that the grid map is filled with lands where DFS goes by M×N deep.
*/
class Solution
{
public:
    std::vector<std::vector<int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
    int nx;
    int ny;

    bool isValid(const int& x, const int& y)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return false;
        return true;
    }

    void dfs(std::vector<std::vector<char>>& grid, int x, int y)
    {
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';

        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            if (isValid(newx, newy))
            {
                dfs(grid, newx, newy);
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        nx = grid.size();
        ny = grid[0].size();
        int res = 0;

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};

//approach 3 iterative dfs
class Solution
{
public:
    std::vector<std::vector<int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
    int nx;
    int ny;

    bool isValid(const int& x, const int& y)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return false;
        return true;
    }

    void dfs(std::vector<std::vector<char>>& grid, int x, int y)
    {
        std::stack<std::pair<int, int>> stk;
        stk.push({ x,y });

        while (!stk.empty())
        {
            auto [i, j] = stk.top();
            stk.pop(); //for stack cannot pop at end
            grid[i][j] = '0';
            for (auto& dir : directions)
            {
                int newx = i + dir[0];
                int newy = j + dir[1];
                if (isValid(newx, newy))
                {
                    if (grid[newx][newy] == '1')
                    {
                        stk.push({ newx,newy });
                        grid[newx][newy] = '0';
                    }
                }
            }
            //stk.pop(); //wrong, for stack cannot pop at end, coz last in last out
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        nx = grid.size();
        ny = grid[0].size();
        int res = 0;

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};


