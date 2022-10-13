#include <vector>

class Solution
{
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2)
    {
        //min(x2) > max(x1)
        //and min(y2) > max(y1)

        return std::min(rec1[2], rec2[2]) > std::max(rec1[0], rec2[0])
            && std::min(rec1[3], rec2[3]) > std::max(rec1[1], rec2[1]);
    }
};