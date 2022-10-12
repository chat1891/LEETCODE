#include <vector>
class Solution
{
public:
    int firstMissingPositive(std::vector<int>& nums)
    {

        int n = nums.size();
        int outBound = (n + 2) * (-1);

        //get rid of negative values
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = 0;
            }
        }

        //the result is between [1,n+1]
        //set the cell to be -ve if it is within the bounds
        for (int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]) - 1;
            if (idx >= 0 && idx < n)
            {
                if (nums[idx] > 0)
                {
                    nums[idx] *= -1;
                }
                else if (nums[idx] == 0)
                {
                    //if the number is 0, idx = -1, it will not get to here
                    //that means it never get visited
                    //[0,1,2]
                    nums[idx] = outBound;
                }
            }


        }

        for (int i = 1; i < n + 1; i++)
        {
            int idx = i - 1;
            if (nums[idx] >= 0)
            {
                return i;
            }
        }

        return n + 1;
    }
};