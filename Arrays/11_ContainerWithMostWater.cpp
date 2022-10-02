#include <vector>

//You have two heights H_left and H_right, and H_right < H_left, then we know we have two choices, 
//we want to move one of them. If we move the larger one, we cannot increase the height for the simple reason that we are always limited by the shortest, 
//and we would be decreasing j-i, the width as well.

//To clarify: let's say we kept the shortest forever, what would happen? Well, j-i would decrease, and either we come across a taller block, which doesn't matter because our shorter one we kept only mattered, or we find a shorter one, in which case that one matters.

//Either way we end up with a smaller area, so we must move the shorter one because moving the larger one cannot give an increase in area.
class Solution
{
public:
    int maxArea(std::vector<int>& height)
    {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int curArea = std::min(height[left], height[right]) * (right - left);
            area = std::max(curArea, area);
            //height is depends on the smallest one
            //if kept the smaller height, move right one, the width decreases
            //area will get smaller
            //so shift the smaller height
            if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return area;
    }
};