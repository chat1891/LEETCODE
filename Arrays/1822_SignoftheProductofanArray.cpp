#include <vector>

class Solution
{
public:
    int arraySign(std::vector<int>& nums)
    {
        int res = 1;
        int countNeg = 0;
        for (auto& num : nums)
        {
            if (num < 0)
            {
                countNeg++;
            }
            else if (num == 0)
            {
                return 0;
            }
        }

        if (countNeg % 2 == 0) return 1;
        return -1;
    }
};