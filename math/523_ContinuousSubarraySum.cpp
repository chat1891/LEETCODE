#include <vector>
#include<unordered_map>

//time O(n)
//space O(min(nums.size(),k))
//because only have k different reminders
class Solution
{
public:
    bool checkSubarraySum(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        int rem = 0;
        int sum = 0;
        std::unordered_map<int, int> mp; //reminder, index
        //if same reminder's index bigger than 1, means has continuous at least two elements
        mp.insert({ 0,-1 }); //prevent first element is multiple of k

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            rem = sum % k;

            if (mp.count(rem) != 0)
            {
                //if find same reminder, 
                //means whatever in between these two are multiple of k
                //till i=2, reminder is 5
                //till i=6, reminder is 5 again
                //sum at i=6 - sum at i=2, reminder canceled out to 0
                if (i - mp[rem] > 1)
                    return true;
            }
            else
            {
                mp[rem] = i;
            }
        }

        return false;
    }
};

//Time limit exceed
//time O(n^2)
//Space O(n)

/*
calculate prefix sum
for each prifix sum, calculate each subarray length>1
*/

class Solution
{
public:
    bool checkSubarraySum(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        std::vector<int> prefixSum(n + 1);
        int curSum = 0;
        for (int i = 1; i <= n; i++)
        {
            curSum += nums[i - 1];
            prefixSum[i] = curSum;
            if (i >= 2 && curSum % k == 0) return true;
        }

        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; i - j >= 2; j++)
            {
                if ((prefixSum[i] - prefixSum[j]) % k == 0)
                {
                    return true;
                }
            }
        }

        return false;
    }
};