#include <vector>
/*
dp[day][has/no stock] = profit

- dp[day][has stock] =
max:
dp[day-1][has stock], previous day has stock, today do nothing
dp[day-1][no stock]-price[day], previous day no stock, today buy

- dp[day][no stock] =
max: 
dp[day-1][has stock]+price[day], prev day has stock sell it today
dp[day-1][has no stock], prev day has no stock do nothing today


Time O(n)
Space O(N)
*/

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][1] = std::max(dp[i - 1][1],dp[i - 1][0] - prices[i]);

            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        }
        return dp[n - 1][0];
    }
};

//=============================================================
//optimization to space O(1)
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int n = prices.size();
        int lastSold = 0;
        int lastBuy = -prices[0];

        for (int i = 1; i < n; i++)
        {
            int curBuy = std::max(lastBuy, lastSold - prices[i]);

            int curSold = std::max(lastSold, lastBuy + prices[i]);
            lastBuy = curBuy;
            lastSold = curSold;
        }
        return lastSold;
    }
};

//====================================================================
//if previous price is smaller, add the difference to profit
//because can trade infinite number of times
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                maxProfit += (prices[i] - prices[i - 1]);
            }
        }
        return maxProfit;
    }
};