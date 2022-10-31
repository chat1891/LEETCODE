#include <vector>

/*
dp[i][k][0]:
    max:
    dp[i-1][k][0]
    dp[i-1][k][1]+prices[i]

//transaction-1 when buy stock
dp[i][k][1]:
    max:
    dp[i-1][k][1]
    //because pruchase is one transaction, so previous is k-1
    //k is the number of transaction has done
    dp[i-1][k-1][0]-prices[i]
*/


class Solution
{
public:
    int maxProfit(int k, std::vector<int>& prices)
    {
        int n = prices.size();
        //day, num transaction did, has/no stock
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