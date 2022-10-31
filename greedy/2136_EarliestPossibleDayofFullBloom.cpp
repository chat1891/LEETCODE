// the earlier you plant a plant that takes time to grow, the earlier it blooms.
//it is better to plant the seed with a longer growth time before the one with a shorter growth time.
#include <vector>
#include <algorithm>
class Solution
{
public:
    int earliestFullBloom(std::vector<int>& plantTime, std::vector<int>& growTime)
    {
        int n = plantTime.size();
        std::vector<std::vector<int>> times;
        for (int i = 0; i < n; i++)
        {
            times.push_back({ plantTime[i],growTime[i] });
        }

        //sort growth time in descending order
        //plant flowers with more time to grow first
        sort(times.begin(), times.end(),
            [](std::vector<int>& a, std::vector<int>& b)
            {
                return a[1] > b[1];
            });

        int res = 0;
        int curPlantTime = 0;
        for (int i = 0; i < n; i++)
        {
            curPlantTime += times[i][0];
            res = std::max(res, curPlantTime + times[i][1]);
        }

        return res;
    }
};