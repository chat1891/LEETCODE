#include <vector>


//official solution is well written
//time O(n^2)
//space O(n)
class Solution
{
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        int n = nums.size();
        int res = 1;

        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            //iterates every number before i,
            //if it is smaller than cur(nums[i]), update
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i])
                {
                    dp[i] = std::max(dp[prev] + 1, dp[i]);
                }
                res = std::max(dp[i], res);
            }
        }


        return res;
    }
};


//use lower bound
class Solution
{
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 1) return n;
        std::vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            if (dp.back() < nums[i])
            {
                dp.push_back(nums[i]);
            }
            else
            {
                //before: [2,3,7,101]
                //nums[i] = 18
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                //find the first one in the list that is bigger than nums[i]
                //itr points to 101
                // 
                  //(lower bound=> if [4,10], nums[i] = 3)
                  //will replace 4 => [3,10];

                *itr = nums[i];
                //replace the one bigger than nums[i] with nums[i], since it is pointer
                //replace [2,3,7,101] to [2,3,7,18]

            }
        }
        return dp.size();
    }
};