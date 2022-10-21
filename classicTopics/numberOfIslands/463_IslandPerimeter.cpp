#include<vector>
#include<queue>


class Solution
{
public:
    int m;
    int n;
    //only check right and down neighbor
    //left and up neighbor covered by previous square
    std::vector<std::vector<int>> directions = { {0,1},{1,0} };
    int res = 0;

    bool isValid(const int& i, const int& j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    //each square adds 4 edges
                    res += 4;
                    //check its right and down neighbor
                    for (auto& dir : directions)
                    {
                        int newx = i + dir[0];
                        int newy = j + dir[1];
                        //if find another land, minus 2 edges
                        if (isValid(newx, newy) && grid[newx][newy] == 1)
                        {
                            res -= 2;
                        }
                    }
                }
            }
        }

        return res;
    }
};

//===============================
/*
approach 2
bfs
- every square has 4 edges
- set visited square to -1
- for each square that is 1, add 4 to result
- check all 4 directions, find a neighbor that is not 0, decrease a edge

*/
class Solution
{
public:
    int m;
    int n;
    std::vector<std::vector<int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };
    int res = 0;

    bool isValid(const int& i, const int& j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    void bfs(std::vector<std::vector<int>>& grid, int x, int y)
    {
        std::queue<std::pair<int, int>> que;
        que.push({ x,y });
        grid[x][y] = -1;
        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();
            //every square has 4 edge
            res += 4;
            for (auto& dir : directions)
            {
                int newx = x + dir[0];
                int newy = y + dir[1];

                if (isValid(newx, newy))
                {
                    if (grid[newx][newy] != 0)
                    {
                        // if visited land, it is -1
                        // if it is not visited land, it is 1
                        //if find a neighbor, minus a edge
                        res--;
                    }

                    if (grid[newx][newy] == 1)
                    {
                        //add to queue, if land is not visited
                        que.push({ newx,newy });
                        grid[newx][newy] = -1;
                    }
                }
            }
        }
    }

    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    bfs(grid, i, j);
                    break;
                }
            }
        }

        return res;
    }
};


/*
- for each land, only check right and down neighbor
- if find another land, minus 2 edges
- left and up neighbor covered by previous square
*/
class Solution_2
{
public:
    int m;
    int n;
    //only check right and down neighbor
    //left and up neighbor covered by previous square
    std::vector<std::vector<int>> directions = { {0,1},{1,0} };
    int res = 0;

    bool isValid(const int& i, const int& j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    //each square adds 4 edges
                    res += 4;
                    //check its right and down neighbor
                    for (auto& dir : directions)
                    {
                        int newx = i + dir[0];
                        int newy = j + dir[1];
                        //if find another land, minus 2 edges
                        if (isValid(newx, newy) && grid[newx][newy] == 1)
                        {
                            res -= 2;
                        }
                    }
                }
            }
        }

        return res;
    }
};