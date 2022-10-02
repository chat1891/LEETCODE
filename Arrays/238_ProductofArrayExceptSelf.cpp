#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 1) return nums;

        std::vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int r = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] = res[i] * r;
            r *= nums[i];
        }

        return res;

    }
};