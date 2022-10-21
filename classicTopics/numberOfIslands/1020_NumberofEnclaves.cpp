#include <vector>

/*
- use dfs to find all the islands
- if any islands pass through a edge point, mark as isEdge then dont add to result
- otherwise add island count to result

time complexity: O(m n)
space complexity: O(m n)
*/
class Solution
{
public:
    int m, n;
    std::vector<std::vector<int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };

    bool isValid(const int& x, const int& y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    int dfs(std::vector<std::vector<int>>& grid, int x, int y, std::vector<std::vector<int>>& visited, int& count, bool& isEdge)
    {
        //pass through edge, mark as isEdge, dont at to result later
        if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
        {
            isEdge = true;
        }

        count++;
        visited[x][y] = true;
        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            if (isValid(newx, newy) && grid[newx][newy] == 1 && !visited[newx][newy])
            {
                dfs(grid, newx, newy, visited, count, isEdge);
            }
        }
        return count;
    }

    int numEnclaves(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, false));

        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int count = 0;
                    bool isEdge = false;
                    dfs(grid, i, j, visited, count, isEdge);
                    if (!isEdge)
                    {
                        res += count;
                    }
                }

            }
        }

        return res;
    }
};

//-----------------------------------------------------------------------------
/// <summary>
/// can use boundary condition to mark if it is pass through edges
/// </summary>
class Solution
{
public:
    int m, n;
    std::vector<std::vector<int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };

    bool isValid(const int& x, const int& y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    int dfs(std::vector<std::vector<int>>& grid, int x, int y, std::vector<std::vector<int>>& visited, int& count)
    {
        if (!isValid(x, y)) return 1; //mark as pass through boundary
        if (visited[x][y]) return 0;
        if (grid[x][y] == 0) return 0;

        int edge = 0;
        count++;
        visited[x][y] = true;
        for (auto& dir : directions)
        {
            int newx = x + dir[0];
            int newy = y + dir[1];
            edge += dfs(grid, newx, newy, visited, count);

        }
        return edge;
    }

    int numEnclaves(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, false));

        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int count = 0; //number of island cell
                    int edge = dfs(grid, i, j, visited, count);
                    if (edge == 0)
                    {
                        res += count;
                    }
                }

            }
        }

        return res;
    }
};