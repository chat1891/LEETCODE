#include <vector>

//https://www.youtube.com/watch?v=I7j0F7AHpb8

class Solution
{
public:
    int n;
    int dfs(std::vector<int>& prices, int day, bool isBuying, std::vector<std::vector<int>>& dp)
    {
        if (day >= n) return 0;
        if (dp[day][isBuying] != -1) return dp[day][isBuying];

        int cooldown = dfs(prices, day + 1, isBuying, dp);
        if (isBuying)
        {
            int buy = dfs(prices, day + 1, false, dp) - prices[day];
            dp[day][isBuying] = std::max(cooldown, buy);
        }
        else
        {
            //day+2, because of 1 day cooldown
            int sell = dfs(prices, day + 2, true, dp) + prices[day];
            dp[day][isBuying] = std::max(sell, cooldown);
        }

        return dp[day][isBuying];
    }

    int maxProfit(std::vector<int>& prices)
    {
        n = prices.size();
        //allocate extra for [1]
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1)); //[day index][isBuying] = profit

        return dfs(prices, 0, 1, dp);
    }
};