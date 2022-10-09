#include <stack>
#include <algorithm>
#include <vector>

/*
Intuition;
- use monotonic stack
- width is between previous small and next small
- area is current height * width

*/

//https://www.youtube.com/watch?v=zx5Sw9130L0&t=489s
//https://www.youtube.com/watch?v=mesaogfSjD4

class Solution
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        //the stack is in increasing order
        std::stack<std::pair<int, int>> stk; //idx, current height
        int area = 0;
        int n = heights.size();

        for (int i = 0; i < heights.size(); i++)
        {
            //current is smaller than last rectangle, 
            //breaks increasing order, means we find next small, so we pop
            int start = i;
            while (!stk.empty() && heights[i] < stk.top().second)
            {
                //update area before popping        
                auto& [preIdx, h] = stk.top();
                area = std::max(area, h * (i - preIdx));
                //because previous one is smaller,
                //we can extend backwards, trying to update index to previous small
                start = preIdx;
                stk.pop();
            }
            stk.push({ start,heights[i] });
        }

        //if the stack in not empty
        //means they can be extended to the end
        while (!stk.empty())
        {
            auto& [preIdx, h] = stk.top();
            //because can be extended to the end
            //width is length of heights - idx
            area = std::max(area, h * (n - preIdx));
            stk.pop();
        }

        return area;
    }
};


