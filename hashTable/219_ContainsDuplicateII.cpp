#include <vector>
#include <set>

/*
- using hash set to keep only K elements
- when set size is >k, remove number[i-k]
*/
class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        std::set<int> mp; //only keep k elements
        //so all the elements in set will have index gap <= k

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (mp.count(nums[i]) != 0)
            {
                return true;
            }

            //careful, insert before
            mp.insert(num);
            if (mp.size() > k)
            {
                //remove the first item
                mp.erase(nums[i - k]);
            }


        }
        return false;
    }
};