#include<string>
#include <vector>

//https://www.youtube.com/watch?v=Ua0GhsJSlWM

/*
bottom up dp, check google doc notes
- when text[i] == text [j]
    dp[i][j] = dp[i+1][j+1]+1;
- when text[i] != text [j]
    dp[i][j] = std::max(dp[i+1][j],dp[i][j+1]);

*/
class Solution
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        int n1 = text1.length();
        int n2 = text2.length();
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};