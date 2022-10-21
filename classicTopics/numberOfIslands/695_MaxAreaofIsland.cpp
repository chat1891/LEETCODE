#include <vector>
#include <stack>

/// <summary>
/// approach 1: recursion
/// </summary>
class Solution
{
public:
    std::vector<std::vector<int>> directions = { {1,0},{-1,0},{0,-1},{0,1} };
    int res = 0, nx, ny;

    bool isValid(int& x, int& y, std::vector<std::vector<int>>& grid)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return false;
        return grid[x][y] == 1;
    }

    int dfs(std::vector<std::vector<int>>& grid, int x, int y, int& count)
    {
        if (grid[x][y] == 1)
        {
            grid[x][y] = 0;
            count++;
            for (auto& dir : directions)
            {
                int newx = x + dir[0];
                int newy = y + dir[1];
                if (isValid(newx, newy, grid))
                {
                    dfs(grid, newx, newy, count);
                }
            }
        }
        return count;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        nx = grid.size();
        ny = grid[0].size();

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                int count = 0;
                if (grid[i][j] == 1)
                {
                    res = std::max(res, dfs(grid, i, j, count));
                }
            }
        }
        return res;
    }
};

///=======================================================================

/// <summary>
/// apparoach2: iterative
/// </summary>
class Solution
{
public:

    int numRow;
    int numCol;
    //vector<pair<int, int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
    std::vector<std::pair<int, int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        numRow = grid.size();
        numCol = grid[0].size();
        int Count = 0;
        int maxCount = 0;

        std::stack<std::pair<int, int>> stk;
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                if (maxCount < Count)
                {
                    maxCount = Count;
                }
                Count = 0;
                if (grid[i][j] == 1)
                {

                    stk.push({ i,j });
                    while (!stk.empty())
                    {
                        Count++;
                        std::pair<int, int> cur = stk.top();
                        stk.pop();
                        grid[cur.first][cur.second] = 0;
                        for (auto direction : directions)
                        {
                            std::pair<int, int> neighbor = { cur.first + direction.first, cur.second + direction.second };
                            if (neighbor.first >= 0 && neighbor.first < numRow && neighbor.second >= 0 && neighbor.second < numCol && grid[neighbor.first][neighbor.second] == 1)
                            {
                                stk.push(neighbor);
                                grid[neighbor.first][neighbor.second] = 0;
                                //maxCount++;
                            }
                        }
                    }
                }
            }
        }
        return std::max(maxCount, Count);

    }
};