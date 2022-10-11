#include <stack>
#include <algorithm>
#include <vector>

/*
Intuition;
- use monotonic stack
- width is between previous smaller and next smaller
- area is current height * width

*/

//https://www.youtube.com/watch?v=xba0NzSbuas
class Solution
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        std::stack<int> stk;
        int n = heights.size();
        std::vector<int> prevSmaller(n, -1); //* init to -1
        std::vector<int> nextSmaller(n, n); //* init to n

        //find next smaller height
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        //clear stack
        while (!stk.empty()) stk.pop();

        //find previous smaller stack
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int curArea = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i];
            res = std::max(res, curArea);
        }

        return res;
    }
};

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


