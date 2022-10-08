#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int cur = nums[0];
        int count = 1;
        int p1 = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (cur == nums[i])
            {
                if (count < 2)
                {
                    //only update cells with count is less than 2
                    nums[p1++] = cur;
                    count++;
                }
                //keep going to the next value if count is bigger than 2
            }
            else
            {
                //get a new number
                //reset count
                cur = nums[i];
                count = 1;
                nums[p1++] = cur;
            }
        }

        return p1;
    }
};