#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximumBags(std::vector<int>& capacity, std::vector<int>& rocks, int additionalRocks)
    {
        std::vector<int> difference; //diff, idx
        int n = capacity.size();
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int diff = capacity[i] - rocks[i];
            if (diff > 0)
            {
                difference.push_back(diff);
            }
            else
            {
                res++;
            }
        }
        //sort to fill in the bags that need less rocks
        sort(difference.begin(), difference.end());
        for (auto& canAdd : difference)
        {
            if (additionalRocks >= canAdd)
            {
                res++;
                additionalRocks -= canAdd;
            }
            else
            {
                break;
            }
        }

        return res;

    }
};