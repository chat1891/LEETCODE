#include <vector>
/*
Let's say the range of the current jump is [curBegin, curEnd],
curFarthest is the farthest point that all points in [curBegin, curEnd] can reach.
Once the current point reaches curEnd,
then trigger another jump, and set the new curEnd with curFarthest,
then keep the above steps
*/

class Solution
{
public:
    int jump(std::vector<int>& nums)
    {
        int l = 0;
        int r = 0;
        int res = 0;
        int farthest = 0;

        while (r < nums.size() - 1)
        {
            //find how far we can reach from current window
            for (int i = l; i <= r; i++)
            {
                farthest = std::max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;

            res++;
        }

        return res;
    }
};