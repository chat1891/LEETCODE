#include <vector>
#include <sstream>
#include <unordered_set>

/*
intuition
- find a start point to explore its up,down,left,right neighbors
- record the explore path, remember to add "_end" after each point otherwise might get different path with same string
- using hash set to check if there is a duplicated path string

Time Complexity : O(M N)
M is number of rows and N is number of columns 

Space Complexity: O(M N) for the hash set and dfs stack
*/

class Solution
{
public:
    int nx, ny;

    void dfs(std::vector<std::vector<int>>& grid, int x, int y, std::stringstream& path, std::string dir)
    {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return;
        if (grid[x][y] == 0)
        {
            return;
        }

        grid[x][y] = 0;
        path << dir;
        dfs(grid, x - 1, y, path, "u"); //move up
        dfs(grid, x + 1, y, path, "d");//move down
        dfs(grid, x, y - 1, path, "l");//move left
        dfs(grid, x, y + 1, path, "r"); //move right
        //**need to mark end to know this point finishes explore its neighbors
        //otherwise might get different path with same string
        path << "_end";
    }

    int numDistinctIslands(std::vector<std::vector<int>>& grid)
    {
        nx = grid.size();
        ny = grid[0].size();
        std::unordered_set<std::string> paths;

        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                std::stringstream path;
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, path, "start_");
                    paths.insert(path.str());
                }
            }
        }
        return paths.size();
    }
};