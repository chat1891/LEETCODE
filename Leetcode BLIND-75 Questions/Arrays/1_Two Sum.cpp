
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end())
            {
                return vector{ mp[diff],i };
            }
            mp.insert({ nums[i],i });
        }
        return vector{ 0,0 };
    }
};