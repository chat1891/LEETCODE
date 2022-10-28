#include<vector>
#include <algorithm>

//two pointers
//cannot use hash set, because it is not a exact target
//time O(n^2)
class Solution
{
public:
    int threeSumSmaller(std::vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < nums.size()-2; i++)
        {
            int& a = nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int three = a + nums[left] + nums[right];
                if (three >= target)
                {
                    right--;
                }
                else
                {
                    count += right - left; //it is not only adding 1, everything between will satisfy the condition
                    left++;
                }
            }
        }

        return count;
    }
};