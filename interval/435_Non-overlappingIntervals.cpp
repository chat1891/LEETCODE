#include<vector>
#include <algorithm>
/*
** Logic**
-sort
- check if interval 1's end < interval 2's start;
-if yes: then no overlapping
- if no : overlapping, remove the one with larger end
because there is a higher chance that the one with larger end will overlap with next interval.it left more time for the rest
[1, 4], [3, 4] vs[1, 2], [3, 4]
- update end to the new value

Time and space complexity
- Time complexity : O(nlog n) + O(n) = O(nlog n); (sort + traversal)
- Space Complexity : O(1)

*/

class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        int count = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            int& curStart = intervals[i][0];
            int& curEnd = intervals[i][1];
            if (curStart < prevEnd)
            {
                //overlap
                count++;
                //remove the one with larger end
                //update prevEnd
                prevEnd = std::min(curEnd, prevEnd);
            }
            else
            {
                //no overlapping
                //update end to the new end
                prevEnd = curEnd;
            }
        }

        return count;
    }
};
