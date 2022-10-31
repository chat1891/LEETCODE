/*
dp[i][k][0]
    max:
    dp[i-1][k][0]
    dp[i-1][k][1]+prices[i]

//transaction when purchase stock
dp[i][k][1]
    max:
    dp[i-1][k][1]
    dp[i-1][k-1][0]-prices[i]

*/

#include <vector>
class Solution
{
public:
    int maxProfit(int k, std::vector<int>& prices)
    {
        int n = prices.size();
        int dp[n][k + 1][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            for (int kk = k; kk >= 1; kk--)
            {
                if (i == 0)
                {
                    dp[i][kk][0] = 0;
                    dp[i][kk][1] = -prices[0];
                }
                else
                {
                    dp[i][kk][0] = std::max(dp[i - 1][kk][0], dp[i - 1][kk][1] + prices[i]);
                    dp[i][kk][1] = std::max(dp[i - 1][kk][1], dp[i - 1][kk - 1][0] - prices[i]);
                }

            }
        }

        return dp[n - 1][k][0];
    }
};


//=================================================================
//optimize space
/*
dp[i][k][0]
    max:
    dp[i-1][k][0]
    dp[i-1][k][1]+prices[i]

//transaction when purchase stock
dp[i][k][1]
    max:
    dp[i-1][k][1]
    dp[i-1][k-1][0]-prices[i]

*/

class Solution
{
public:
    int maxProfit(int k, std::vector<int>& prices)
    {
        int n = prices.size();

        //if k is bigger than n/2, considered as unlimited number of transactions
        //use less memory
        if (2 * k > n)
        {
            int res = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] - prices[i - 1] > 0)
                    res += (prices[i] - prices[i - 1]);
            }
            return res;
        }


        int dp[n][k + 1][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            for (int kk = k; kk >= 1; kk--)
            {
                if (i == 0)
                {
                    dp[i][kk][0] = 0;
                    dp[i][kk][1] = -prices[0];
                }
                else
                {
                    dp[i][kk][0] = std::max(dp[i - 1][kk][0], dp[i - 1][kk][1] + prices[i]);
                    dp[i][kk][1] = std::max(dp[i - 1][kk][1], dp[i - 1][kk - 1][0] - prices[i]);
                }

            }
        }

        return dp[n - 1][k][0];
    }
};