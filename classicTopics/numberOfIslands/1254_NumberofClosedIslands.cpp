#include <vector>

/// <summary>
/// approach 1 dfs
/// </summary>
class Solution
{
public:
    int nx, ny;
    std::vector<std::vector<int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };

    bool dfs(std::vector<std::vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return false;
        if (grid[x][y] == 1) return true; //surrounded by water

        grid[x][y] = 1; //marked as visited, change to water

        //** THIS WILL NOT NOT WORK
        //***if isClosed is false, because of using and operator, rest of dfs will not excute!!!!
        //bool isClosed = true;
        //for(auto& dir:directions){        
            //isClosed = isClosed && dfs(grid, x+dir[0], y+dir[1]);
        //}

        bool d1 = dfs(grid, x + 1, y);
        bool d2 = dfs(grid, x - 1, y);
        bool d3 = dfs(grid, x, y + 1);
        bool d4 = dfs(grid, x, y - 1);

        return d1 && d2 && d3 && d4;
    }

    int closedIsland(std::vector<std::vector<int>>& grid)
    {
        int res = 0;
        nx = grid.size();
        ny = grid[0].size();

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(grid, i, j))
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

//========================================================================
//because mistake easily made with and operator in approach 1
//can use int instead
class Solution
{
public:
    int nx, ny;
    std::vector<std::vector<int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };

    int dfs(std::vector<std::vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return 1;
        if (grid[x][y] == 1) return 0; //surrounded by water

        grid[x][y] = 1; //marked as visited, change to water

        int isClosed = 0;
        for (auto& dir : directions)
        {
            isClosed += dfs(grid, x + dir[0], y + dir[1]);
        }
        return isClosed;
    }

    int closedIsland(std::vector<std::vector<int>>& grid)
    {
        int res = 0;
        nx = grid.size();
        ny = grid[0].size();

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(grid, i, j) == 0)
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};