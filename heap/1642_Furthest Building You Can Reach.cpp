#include <queue>
using namespace std;


class Solution
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        //Min Heap
        priority_queue< int, vector<int>, greater<int>> onlyUseLadder;

        for (int i = 0; i < heights.size() - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0) continue;

            onlyUseLadder.push(diff);
            if (onlyUseLadder.size() <= ladders)
            {
                continue;
            }

            //because run out of ladders, 
            //have to use bricks at least once
            bricks -= onlyUseLadder.top();
            onlyUseLadder.pop();

            if (bricks < 0)
            {
                return i;
            }
        }

        return heights.size() - 1;
    }
};


//use dp, but too slow, exceed memory/time limit
class Solution
{
public:
    int n;
    vector<vector<vector<int>>> dp;

    int dfs(vector<int>& heights, int bricks, int ladders, int i)
    {
        if (bricks < 0 && ladders < 0) return 0;
        if (dp[i][bricks][ladders] != -1) return dp[i][bricks][ladders];

        if (i < n - 1)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0)
            {

                return dp[i][bricks][ladders] = 1 + dfs(heights, bricks, ladders, i + 1);
            }

            int useBrick = 0;
            int useLadder = 0;
            if (bricks - diff >= 0)
            {
                useBrick = 1 + dfs(heights, bricks - diff, ladders, i + 1);
            }
            if (ladders - 1 >= 0)
            {
                useLadder = 1 + dfs(heights, bricks, ladders - 1, i + 1);
            }

            return dp[i][bricks][ladders] = max(useBrick, useLadder);
        }
        return 0;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        n = heights.size();
        //needs to be three dimensional dp, because height index is also changing
        dp = vector<vector<vector<int>>>(heights.size() + 1, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));

        return dfs(heights, bricks, ladders, 0);
    }
};