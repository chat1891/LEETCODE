#include <vector>

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        int Left = 0;
        int n = height.size() - 1;
        int Right = n;
        int maxLeft = height[Left];
        int maxRight = height[Right];
        int res = 0;

        while (Left < Right)
        {
            if (maxRight < maxLeft)
            {
                //shift the side with smaller value

                if (maxRight - height[Right] > 0)
                {
                    res += (maxRight - height[Right]);
                }

                Right--;
                maxRight = std::max(maxRight, height[Right]);
            }
            else
            {
                if (maxLeft - height[Left] > 0)
                {
                    res += (maxLeft - height[Left]);
                }

                Left++;
                maxLeft = std::max(maxLeft, height[Left]);

            }
        }

        return res;
    }
};