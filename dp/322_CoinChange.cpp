#include <vector>
//similar to 1155 Number of Dice Rolls With Target Sum
class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        int n = coins.size();
        //use INT_MAX-1 to prevent stack overflow
        //because at line 13, it is 1+dp
        std::vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;

        for (int a = 1; a <= amount; a++)
        {
            for (const auto& coin : coins)
            {
                if (a - coin >= 0)
                {
                    dp[a] = std::min(dp[a], 1 + dp[a - coin]);
                }
            }
        }

        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};