#include <vector>
#include <map>
#include <algorithm>

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


//-----------------------------------------------------------------
//approach 2 two pointers
//this method cannot use map, because it has duplicated values in the nums
//map only saves same value once
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> numsCopy = nums;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int s = 0, e = 0;

        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                left++;
            }
            else if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                s = nums[left];
                e = nums[right];
                break;
            }
        }

        for (int i = 0; i < numsCopy.size(); i++)
        {
            if (numsCopy[i] == s)
            {
                s = i;
                break;
            }
        }

        for (int i = numsCopy.size() - 1; i >= 0; i--)
        {
            if (numsCopy[i] == e)
            {
                e = i;
                break;
            }
        }

        return { s,e };
    }
};