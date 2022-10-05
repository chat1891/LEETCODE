#include <vector>

//When nums[j] equals to the given value, skip this element by incrementing j. 
//As long as nums[j] != val, copy nums[j] to nums[i]
class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};