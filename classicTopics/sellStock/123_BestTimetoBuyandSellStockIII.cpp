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

#include <vcruntime_string.h>
#include <algorithm>
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 1) return 0;

        //day, num transaction did, has/no stock
        int dp[n][3][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][2][0] = 0;
        dp[0][2][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            for (int k = 2; k >= 1; k--)
            {
                dp[i][k][0] = std::max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = std::max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][2][0];

    }
};