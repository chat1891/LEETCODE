#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int curSubarray = nums[0];
        int maxSubarray = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int num = nums[i];
            //if negative, we dont add
            curSubarray = std::max(num, curSubarray + num);
            maxSubarray = std::max(maxSubarray, curSubarray);
        }
        return maxSubarray;
    }
};

class Solution_2
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int maxSum = nums[0];
        int curSum = 0;

        for (auto& num : nums)
        {
            if (curSum < 0)
            {
                //reset if it is negative
                curSum = 0;
            }
            curSum += num;
            maxSum = std::max(curSum, maxSum);
        }

        return maxSum;
    }
};