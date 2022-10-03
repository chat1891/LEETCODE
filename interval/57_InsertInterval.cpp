#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
    {
        std::vector<std::vector<int>> res;
        int n = intervals.size();
        bool added = false;

        for (int i = 0; i < n; i++)
        {
            //if no overlap, newInterval is after intervals[i]
            //intervals[i] = [1,2]
            //newInterval = [4,5]
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
            }
            else if (newInterval[1] < intervals[i][0])
            {
                //no overlap, newInterval before intervals[i]
                //intervals[i] = [3,4]
                //newInterval = [1,2]
                res.push_back(newInterval);
                //inserted the new interval, append rest to the result and return
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;

            }
            else
            {
                //overlap
                //update new interval to the new range
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }

        res.push_back(newInterval);
        return res;
    }
};