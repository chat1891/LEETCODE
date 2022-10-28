#include <string>
#include <vector>

//bottom up dp
class Solution
{
public:
    bool isValidPalindrome(std::string s, int k)
    {
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + std::min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1] <= k;
    }
};