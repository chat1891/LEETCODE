#include <vector>

/*
- we shift matrix 1 to overlap with matrix 2
- we count the overlapping ones in the overlapping zone.


time O(n^4)
 - shifting is 2(n-1) * 2(n-1) = n^2 
 - for each shift, calculate overlap is n^2
*/
//https://www.youtube.com/watch?v=Jzs2_6qf78c

class Solution
{
private:
    int overlapOnes(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2, int rowOffset, int colOffset)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int i2 = i + rowOffset;
                int j2 = j + colOffset;
                if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= n)
                {
                    continue;
                }
                if (img1[i][j] + img2[i2][j2] == 2)
                {
                    count++;
                }
            }
        }
        return count;
    }

public:
    int n;
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2)
    {
        n = img1.size();
        int res = 0;
        for (int row = -n + 1; row < n; row++)
        {
            for (int col = -n + 1; col < n; col++)
            {
                res = std::max(res, overlapOnes(img1, img2, row, col));
            }
        }
        return res;
    }
};