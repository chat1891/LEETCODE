#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        //moving from end to start
        //check to see if it possible to move from prev to goal
        //if can move the goal to previous

        int n = nums.size();
        int goal = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int& steps = nums[i];
            if (steps >= (goal - i))
            {
                //[1,2,0,1]
                //goal moves i steps, because at 0, it didn't move
                goal = i; //shift goal to i position
            }
        }

        return goal == 0;
    }
};