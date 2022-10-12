#include <vector>
#include <algorithm>

//to form a triangle a<=b<=c
//a+b > c

class Solution
{
public:
    int largestPerimeter(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int res;
        for (int i = nums.size() - 3; i >= 0; i--)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        return 0;
    }
};