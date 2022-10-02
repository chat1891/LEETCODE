#include<vector>
//https://www.youtube.com/watch?v=lXVy6YWFcRM

//time: O(N)
//SPACE: O(1)
class Solution
{
public:
    int maxProduct(std::vector<int>& nums)
    {
        int curMin = nums[0];
        int curMax = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int cur = nums[i];

            //when calculate curMin, use old curMax, but curMax is updated
            //used temp variable
            int oldCurMax = curMax;
            //[-1,-2,-3,x]
            //at i=2, min = -6, max = 6
            //if x=4 -> res = max * 4 = 6*4=24;
            //if x=-4 -> res = min * (-4) = -6*(-4)=24;
            curMax = std::max(curMin * cur, std::max(curMax * cur, cur));
            curMin = std::min(curMin * cur, std::min(oldCurMax * cur, cur));
            res = std::max(res, curMax);
        }
        return res;
    }
};