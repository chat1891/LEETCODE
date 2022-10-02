#include <vector>

class Solution
{
public:
    int binarySearch(int l, int r, std::vector<int>& nums)
    {
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];

            if (nums[mid] > nums[l])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return -1;
    }

    int findMin(std::vector<int>& nums)
    {
        int n = nums.size();

        //no rotation
        if (n == 1 || nums[0] < nums[n - 1]) return nums[0];

        return binarySearch(0, n - 1, nums);
    }
};