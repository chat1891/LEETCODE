#include <vector>
#include <map>

//logic
//use hash map to insert left value and first index, if find the remaining value, then return
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end())
            {
                return { mp[diff],i };
            }
            mp.insert({ nums[i],i });
        }
        return { 0,0 };
    }
};