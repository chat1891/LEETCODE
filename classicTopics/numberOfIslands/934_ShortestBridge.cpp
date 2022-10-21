// - use dfs to traverse first island, and put every point to queue
// - start popping from queue and do bfs, stop as long as find second island

#include <vector>
#include <queue>
class Solution
{
public:
    std::queue<std::pair<int, int>> que;
    int m, n;
    std::vector<std::vector<int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };

    bool isValid(const int& x, const int& y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    void dfs(std::vector<std::vector<int>>& grid, int i, int j, std::vector<std::vector<int>>& visited)
    {
        if (visited[i][j]) return;
        if (grid[i][j] == 0) return;

        que.push({ i,j });
        visited[i][j] = true;
        for (const auto& dir : directions)
        {
            int newx = i + dir[0];
            int newy = j + dir[1];
            if (isValid(newx, newy) && grid[newx][newy] == 1)
            {
                dfs(grid, newx, newy, visited);
            }
        }
    }

    int shortestBridge(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, false));
        bool found = false;
        //find first island
        for (int i = 0; i < m && !found; i++)
        {
            for (int j = 0; j < n && !found; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, visited);
                    found = true;
                    break;
                }
            }
        }

        int count = 0;
        while (!que.empty())
        {
            int sz = que.size();

            for (int i = 0; i < sz; i++)
            {

                auto [x, y] = que.front();
                visited[x][y] = true;
                que.pop();
                for (auto& dir : directions)
                {
                    int newx = x + dir[0];
                    int newy = y + dir[1];
                    if (isValid(newx, newy) && !visited[newx][newy])
                    {
                        if (grid[newx][newy] == 1)
                            return count;

                        que.push({ newx,newy });
                        visited[newx][newy] = true;
                    }
                }

            }
            count++;

        }
        return -1;

    }
};