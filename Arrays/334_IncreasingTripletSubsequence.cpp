#include <vector>

class Solution
{
public:
    bool increasingTriplet(std::vector<int>& nums)
    {
        int firstNum = INT_MAX;
        int secondNum = INT_MAX;

        for (auto& num : nums)
        {
            //if the number is smaller than first number
            //update first number to it
            //first number is the min seen so far
            if (num <= firstNum)
            {
                firstNum = num;
            }
            else if (num <= secondNum)
            {
                //if first condition failed, means num is bigger than first number
                 // num is better than the second number, store it
                secondNum = num;
            }
            else
            {
                //
                return true;
            }
        }

        return false;
    }
};