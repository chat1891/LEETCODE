#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int minVal = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minVal)
            {
                minVal = prices[i];
            }
            else if (prices[i] - minVal > maxProfit)
            {
                maxProfit = prices[i] - minVal;
            }

        }

        return maxProfit;
    }
};

//dp
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int n = prices.size();
        //[day index] [has stock]
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0]; //day0, just bought a stock
        for (int i = 1; i < n; i++)
        {
            //dont have stock today
            //- yesterday also dont have stock
            //- yesterday has stock but today sold it 
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

            //have stock today
            //- yesterday had stock, today didn't buy
            //- yesterday has no stock but today bought it 
            dp[i][1] = std::max(dp[i - 1][1], -prices[i]);
        }

        return dp[n - 1][0];
    }
};