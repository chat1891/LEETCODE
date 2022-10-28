#include <vector>
#include <algorithm>
#include <unordered_map>


//sort

class Solution
{
public:
    std::vector<int> findErrorNums(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2) return nums;
        sort(nums.begin(), nums.end());
        int dup = 0, missing = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                dup = nums[i];
            }
            else if (nums[i] - nums[i - 1] > 1)
            {
                missing = nums[i - 1] + 1;
            }

        }

        if (nums[n - 1] != n) missing = n;

        return { dup, missing };

    }
};

//================================================================
//hash map
class Solution
{
public:
    std::vector<int> findErrorNums(std::vector<int>& nums)
    {
        std::unordered_map<int, int> mp; //int count
        for (auto& num : nums)
        {
            mp[num]++;
        }

        int dup = 0, missing = 0;

        for (int i = 1; i < nums.size() + 1; i++)
        {
            if (mp.count(i) > 0)
            {
                if (mp[i] == 2)
                    dup = i;
            }
            else
            {
                missing = i;
            }

        }

        return { dup,missing };
    }
};