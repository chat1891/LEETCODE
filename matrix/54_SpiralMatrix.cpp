#include <vector>

/*
       left         right
up      1  2  3  4  5
        6  7  8  9  10
        11 12 13 14 15
        16 17 18 19 20
down    21 22 23 24 25



          left  right
        1  2  3  4  5
up      6  7  8  9  10
        11 12 13 14 15
down    16 17 18 19 20
        21 22 23 24 25

- get top row, right col, bottom row, left row
- shrink left, right, up and down, repeat same process
*/

//https://www.youtube.com/watch?v=BJnMZNwUk1M

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;

        while (left <= right && up <= down)
        {
            //get top row
            for (int y = left; y <= right; y++)
            {
                res.push_back(matrix[up][y]);
            }
            up++;
            //get right column
            for (int x = up; x <= down; x++)
            {
                res.push_back(matrix[x][right]);
            }
            right--;

            //** break if cross
            //[[6,9,7]]
            //[[1,2],[3,4]]
            //add if has one row in center
            if (up <= down)
            {
                //get bottom row
                for (int y = right; y >= left; y--)
                {
                    res.push_back(matrix[down][y]);
                }
            }

            down--;
            if (left <= right)
            {
                //get left column
                for (int x = down; x >= up; x--)
                {
                    res.push_back(matrix[x][left]);
                }
            }
            left++;
        }

        return res;
    }
};


class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;

        while (left <= right && up <= down)
        {
            //get top row
            for (int y = left; y <= right; y++)
            {
                res.push_back(matrix[up][y]);
            }
            up++;
            //get right column
            for (int x = up; x <= down; x++)
            {
                res.push_back(matrix[x][right]);
            }
            right--;

            //** break if cross
            //[[6,9,7]]
            //[[1,2],[3,4]]
            if (left > right || up > down)
                break;

            //get bottom row
            for (int y = right; y >= left; y--)
            {
                res.push_back(matrix[down][y]);
            }
            down--;
            //get left column
            for (int x = down; x >= up; x--)
            {
                res.push_back(matrix[x][left]);
            }
            left++;
        }

        return res;
    }
};