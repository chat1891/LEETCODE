#include <vector>
#include <stack>

//similar to 84 Largest Rectangle in Histogram
//2334. Subarray With Elements Greater Than Varying Threshold
class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix)
    {
        //look at each row as a bar   
        //if it is continuous 1, count the 1s
        //if there is a cut off by 0, count 1 in current row, or 0 if the cell is 0;
        //for example 1, the h is
        //1 0 1 0 0
        //2 0 1 1 1
        //3 1 3 2 2
        //4 0 0 1 0
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> h(cols);
        int res = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (matrix[r][c] == '1')
                {
                    h[c] += 1;
                }
                else
                {
                    h[c] = 0;
                }
            }
            res = std::max(res, largestRectangleArea(h));

        }

        return res;
    }

    //this is same as 84. Largest Rectangle in Histogram
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