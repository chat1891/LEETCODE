#include <vector>

/*
dp[day][has stock] =
    max:
    dp[day-1][has stock], today no transaction
    dp[day-1][no stock]-fee-prices[day], yesterdat no stock, today bought

dp[day][no stock] =
    max:
    dp[day-1][no stock]
    dp[day-1][has stock]-fee + prices[day] //yesterday has stock, today sell it


time: O(n)
space: O(n)
*/


class Solution
{
public:
    int maxProfit(std::vector<int>& prices, int fee)
    {
        int n = prices.size();
        //[day][has/no stock]
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, -1));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            //only add transaction when sell the stock
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - fee + prices[i]);
        }

        //return on last day without stock
        return dp[n - 1][0];
    }
};

//==============================================================
/*

time: O(n)
space: O(1)
*/
class Solution
{
public:
    int maxProfit(std::vector<int>& prices, int fee)
    {
        int n = prices.size();
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < n; i++)
        {
            //i th day i dont own a share today (either did not have or sold today)
            hold = std::max(hold, cash - prices[i]);
            //only add transaction when sell the stock
            //i th day i own a share today (either had one or bought today)
            cash = std::max(cash, hold - fee + prices[i]);
        }

        return cash;
    }
};
