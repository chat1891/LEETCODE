#include <vector>
#include <queue>
#include <tuple>
class Solution
{
public:
    std::vector<std::vector<int>> directions = { {1,1},{1,0},{0,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1} };
    int nx = 0;
    int ny = 0;

    bool isValid(const int& i, const int& j, std::vector<std::vector<int>>& grid)
    {
        if (i < 0 || j < 0 || i >= nx || j >= ny) return false;
        return grid[i][j] == 0;
    }

    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid)
    {
        nx = grid.size();
        ny = grid[0].size();

        //edge case:
        if (grid[0][0] == 1 || grid[nx - 1][ny - 1] == 1) return -1;

        std::queue<std::tuple<int, int, int>> que;//i,j, path length
        //vector<vector<bool>> visited(n,vector<int>(n,false));
        que.push({ 0,0,1 });
        grid[0][0] = 1; //mark start as visited

        while (!que.empty())
        {
            auto& [i, j, pathLength] = que.front();

            if (i == nx - 1 && j == ny - 1)
            {
                return pathLength;
            }

            for (auto& direction : directions)
            {
                int new_i = i + direction[0];
                int new_j = j + direction[1];
                if (isValid(new_i, new_j, grid))
                {
                    grid[new_i][new_j] = 1; //mark as visited
                    //same level has same pathLength
                    que.push({ new_i,new_j,pathLength + 1 });
                }

            }
            que.pop();
            //because auto& [i,j,pathLength] is using reference, pop it after finish using it...

        }

        return -1;
    }
};