//same as 84 Largest Rectangle in Histogram
#include <vector>
#include <stack>

class Solution
{
public:
    int validSubarraySize(std::vector<int>& nums, int threshold)
    {
        std::stack<std::pair<int, int>> stk; //idx, num
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            int start = i;
            while (!stk.empty() && nums[i] < stk.top().second)
            {
                auto& [idx, num] = stk.top();
                int len = i - idx;
                if (num > threshold / len)
                {
                    return len;
                }
                start = idx;
                stk.pop();
            }

            stk.push({ start,nums[i] });
        }

        while (!stk.empty())
        {
            auto& [idx, num] = stk.top();
            int len = n - idx;
            if (num > threshold / len)
            {
                return len;
            }
            stk.pop();
        }

        return -1;


    }
};