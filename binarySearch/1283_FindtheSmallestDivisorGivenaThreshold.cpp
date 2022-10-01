#include <climits>
#include <vector>

class Solution
{
public:
    int divisor = INT_MAX;

    int divisionCeiling(int a, int b)
    {
        return a / b + (a % b > 0);
    }

    void binarySearch(int l, int r, std::vector<int>& nums, const int& threshold)
    {
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int res = 0;
            bool hasResult = true;
            for (int i = 0; i < nums.size(); i++)
            {
                int div = divisionCeiling(nums[i], mid);
                res += div;
                if (res > threshold)
                {
                    hasResult = false;
                    break;
                }
            }

            if (hasResult)
            {
                divisor = std::min(divisor, mid);
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
    }

    int smallestDivisor(std::vector<int>& nums, int threshold)
    {
        int n = nums.size();
        //sort(nums.begin(),nums.end());
        int maxNum = 0;
        for (auto& num : nums) maxNum = max(maxNum, num);

        if (threshold <= n)
        {
            //if threshhold == number of nums,
            //take the biggest number as divisor
            //because every sinlge division needs to be 1
            return maxNum;
        }


        int right = maxNum;
        int left = 1;

        binarySearch(left, right, nums, threshold);

        return divisor;
    }
};