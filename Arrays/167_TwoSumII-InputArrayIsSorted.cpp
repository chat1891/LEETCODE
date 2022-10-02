#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum2 = numbers[left] + numbers[right];
            if (sum2 > target)
            {
                right--;
            }
            else if (sum2 < target)
            {
                left++;
            }
            else
            {
                return { left + 1,right + 1 };
            }
        }
        return { left + 1,right + 1 };
    }
};