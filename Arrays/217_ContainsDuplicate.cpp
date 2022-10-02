#include <set>
#include <vector>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::set<int> mp;
        for (const auto& num : nums)
        {
            if (mp.find(num) != mp.end())
            {
                return true;
            }
            mp.insert(num);
        }
        return false;
    }
};