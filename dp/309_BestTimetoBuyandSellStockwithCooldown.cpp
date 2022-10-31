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

//========================================================
//iterative dp
/*
dp[day][has stock]
    max
    dp[i-1][has stock] //had stock, today do nothing
    dp[i-2][no stock]-prices[i]
    //previous no stock, just bought today
    //**because cool down one day, so use i-2

dp[day][no stock]
    max
    dp[i-1][no stock]
    dp[i-1][has stock]+prices[i] //had stock, sold it
*/

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2) return 0;

        //[day index] [has stock]
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0]; //day0, just bought a stock
        dp[1][0] = std::max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = std::max(dp[0][1], -prices[1]); //max(yesterday has stock, or no stock yesterday bought today)

        for (int i = 2; i < n; i++)
        {
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        }

        return dp[n - 1][0];
    }
};