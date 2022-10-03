#include <vector>
#include <string>

//logic:
//get left bound and right bound of same color group
//only keep one balloon to get distinct color
//so, delete all the other balloons, only keep the biggest one to minimize time
//reset the left pointer to next color group

//Time: O(n)
//Space: O(1)

class Solution
{
public:
    int minCost(std::string colors, std::vector<int>& neededTime)
    {
        int l = 0;
        int r = 0;
        int n = neededTime.size();
        int res = 0;

        while (l < n && r < n)
        {
            int maxTime = 0;
            int curSum = 0;
            //get same color group
            while (r < n && colors[l] == colors[r])
            {
                maxTime = std::max(maxTime, neededTime[r]);
                curSum += neededTime[r];
                r++;
            }
            //for one color group, only keep one balloon
            //to get min time spend, keep the biggest balloon
            int timeSpend = curSum - maxTime;
            res += timeSpend;

            //reset pointers
            l = r;
        }

        return res;
    }
};