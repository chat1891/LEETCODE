#include <vector>
#include<algorithm>
//https://www.youtube.com/watch?v=jzZsG8n2R9A

//time: O(N LOG(N)) + N*N
//      SORT          loop
//space O(1) OR O(n) depends on sorting algorithm

//use two pointers
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            //do not want to check doublicated ones
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            //solve two sum
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int threeSum = a + nums[left] + nums[right];
                if (threeSum > 0)
                {
                    //sum is too big, move right pointer to get smaller num
                    right--;
                }
                else if (threeSum < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back({ a,nums[left],nums[right] });
                    left++;
                    //[-1,-1,0,0,1,1]
                    //left ++ = 1, which is same as previous

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        //move left to 2
                        left++;
                    }
                }
            }
        }
        return res;
    }
};