#include <vector>
#include <algorithm>


class Solution
{
public:
    class myComparator
    {
    public:
        bool operator()(const std::vector<int>& a, const std::vector<int>& b)
        {
            return b[1] < a[1];
        }
    };
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), myComparator());

        int res = 0;

        for (auto& box : boxTypes)
        {
            int& count = box[0];
            int& units = box[1];
            int added = std::min(count, truckSize);

            res += (added * units);
            truckSize -= added;

            if (truckSize == 0)
            {
                return res;
            }
        }
        return res;
    }
};