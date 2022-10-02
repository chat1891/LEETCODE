#include <vector>


//Two pass binary search
//time: O(LOG N)
//SPACE O(N)
class Solution
{
public:
    int binarySearch(std::vector<int>& nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    int findPivot(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[left] < nums[right]) return 0; //no rotation

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) return mid + 1;
            if (nums[mid - 1] > nums[mid]) return mid;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }

        }
        return -1;
    }
    int search(std::vector<int>& nums, int target)
    {
        if (nums.size() == 1) return target == nums[0] ? 0 : -1;

        int pivot = findPivot(nums);
        int l = binarySearch(nums, 0, pivot - 1, target); //search left hand side 
        int r = binarySearch(nums, pivot, nums.size() - 1, target);//search right hand side

        return l == -1 ? r : l;
    }
};

//one pass binary search
//time: O(LOG N)
//SPACE O(N)
class Solution_2
{
public:
    int search(std::vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;

            //at left portion
            if (nums[l] <= nums[mid])
            {
                if (target<nums[l] || target >nums[mid])
                {
                    //serch right portion
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                //at right portion
                if (target<nums[mid] || target > nums[r])
                {
                    //search in left portion
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};