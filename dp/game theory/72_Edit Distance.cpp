#include <vector>
#include <string>
using namespace std;
//https://www.youtube.com/watch?v=XYi2-LPrwm4

class Solution_iterative
{
   
public:
    int minDistance(string word1, string word2)
    {
        int n1 = word1.length();
        int n2 = word2.length();
        //dp[n1][n2]=0 is the base case
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        //fill in base case
        for (int i = n1 - 1; i >= 0; i--)
        {
            dp[i][n2] = n1 - i;
        }
        for (int j = n2 - 1; j >= 0; j--)
        {
            dp[n1][j] = n2 - j;
        }

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = 1 + min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

class Solution_recursion
{
public:
    int n1 = 0;
    int n2 = 0;
    int helper(vector<vector<int>>& dp, int i, int j, string& word1, string& word2)
    {
        if (i == n1) return n2 - j;
        if (j == n2) return n1 - i;
        if (dp[i][j] != -1) { return dp[i][j]; }

        if (word1[i] == word2[j])
        {
            dp[i][j] = helper(dp, i + 1, j + 1, word1, word2);
        }
        else
        {
            dp[i][j] = 1 + min(min(
                helper(dp, i + 1, j, word1, word2), //delete
                helper(dp, i, j + 1, word1, word2)), //insert
                helper(dp, i + 1, j + 1, word1, word2)); //replace
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2)
    {
        n1 = word1.length();
        n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return helper(dp, 0, 0, word1, word2);;
    }
};