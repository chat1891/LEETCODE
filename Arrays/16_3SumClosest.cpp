#include <vector>
#include <algorithm>

class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        int n = nums.size();
        int res = 1e5;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int& a = nums[i];

            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int curSum = a + nums[l] + nums[r];
                if (abs(target - res) > abs(target - curSum))
                {
                    res = curSum;
                }

                if (target - curSum > 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }

        }
        return res;
    }

};