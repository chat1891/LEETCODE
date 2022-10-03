#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::vector<std::vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 0) return res;
        if (n == 1) return intervals;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] < intervals[i][0])
            {
                //no overlap
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};

class Solution_2
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::vector<std::vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 0) return res;
        if (n == 1) return intervals;

        std::vector<int> toMerge = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            //if no overlap, newInterval is after intervals[i]
            //intervals[i] = [1,2]
            //newInterval = [4,5]
            if (toMerge[0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] > toMerge[1])
            {
                //no overlap, newInterval before intervals[i]
                //intervals[i] = [3,4]
                //newInterval = [1,2]
                res.push_back(toMerge);
                toMerge = intervals[i];
            }
            else
            {
                toMerge[0] = std::min(toMerge[0], intervals[i][0]);
                toMerge[1] = std::max(toMerge[1], intervals[i][1]);
            }
        }

        res.push_back(toMerge);
        return res;
    }
};