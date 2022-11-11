#include <vector>

class Solution
{
public:
    int rows;
    int cols;
    bool isValid(int i, int j)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols) return false;
        return true;
    }

    std::vector<int> findBall(std::vector<std::vector<int>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        std::vector<int> res;
        if (rows == 1 && cols == 1) return { -1 };

        //loop each column
        for (int col = 0; col < cols; col++)
        {
            int x = 0;
            int y = col;
            while (true)
            {
                //if current cell is going to right
                if (grid[x][y] > 0)
                {

                    //break if cannot go right anymore
                    //** do not increment x
                    if (!isValid(x, y + 1))
                    {
                        res.push_back(-1);
                        break;
                    }
                    //if next cell is going to left
                    //ball will stuck in V, break
                    if (grid[x][y + 1] == -1)
                    {
                        res.push_back(-1);
                        break;
                    }
                    //if reach last row, add to result
                    if (x == rows - 1)
                    {
                        //**because it directs to right
                        //return y+1
                        res.push_back(y + 1);
                        break;
                    }
                    x++;
                    y++;

                }
                else
                {
                    //going to left direction
                    //break if cannot go left anymore
                    //** do not increment x
                    if (!isValid(x, y - 1))
                    {
                        res.push_back(-1);
                        break;
                    }
                    //if next is right
                    //form v shape. ball stuck
                    if (grid[x][y - 1] == 1)
                    {
                        res.push_back(-1);
                        break;
                    }

                    //reach to last row
                    //**because it directs to left, add y-1
                    if (x == rows - 1)
                    {
                        res.push_back(y - 1);
                        break;
                    }

                    x++;
                    y--;
                }
            }
        }

        return res;
    }
};