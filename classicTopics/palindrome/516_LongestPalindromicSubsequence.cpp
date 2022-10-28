#include <string>
#include <vector>

//top down recommended 
//similar to 5. Longest Palindromic Substring

/*
row = i; column = j, substring from i to j
//fill in from bottom to up, at each level from left to right
//P(i,j) = (P(i+1,j-1) +2)
//P(1,3) = "aba" = P(2,2)

example:
if we want to know babad
1. i=0, j=4, b!=d then we want to know max of("baba" or "abad")
    1.1 for baba i=1,j=4
        - b!=a -> check "bab" and "aba"
            - b==b -> check a. total = 2+1 = 3
            - a==a check b, total = 2+1 = 3
    1.2 FOR "abad" same as before


      j
      b a b a d
i   b 1 N N N N     ^   b, ba, bab, baba, babad
    a   1 N N N     ^   a, ab, aba, abad
    b     1 N N     ^   b, ba, bad
    a       1 N     ^   a, ad
    d         1     ^   d

          j
      b a b a d
i   b 1 N 3 3 N     ^   b, ba, bab, baba, babad
    a   1 N 3 N     ^   a, ab, aba, abad
    b     1 N N     ^   b, ba, bad
    a       1 N     ^   a, ad
    d         1     ^   d

          j
      b a b a d
i   b 1 N 3 3 N     ^   b, ba, bab, baba, babad
    a   1 N 3 3     ^   a, ab, aba, abad
    b     1 0 3     ^   b, ba, bad
    a       1 0     ^   a, ad
    d         1     ^   d

              j
      b a b a d
i   b 1 N 3 3 3     ^   b, ba, bab, baba, babad
    a   1 N 3 3     ^   a, ab, aba, abad
    b     1 0 3     ^   b, ba, bad
    a       1 0     ^   a, ad
    d         1     ^   d


    Time Complexity - O(N^2),
    Space Complexity - O(N^2) (caching all substring)
*/
class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //a(bcb)a
                    //s[0]==s[3], i=0, j=4
                    //dp[i+1][j-1] =dp[1][3] ="bcb"
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        //substring between index 0 to n-1
        return dp[0][n - 1];
    }
};

//===========================================================
//approach 2: use longest common subsequence
//similar to 1143. Longest Common Subsequence
class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        int n = s.length();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        //palindrome is same string if it is reversed
        //basically checking longest common subsequence for string and reversed string
        std::string s2 = s;
        reverse(s2.begin(), s2.end());

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == s2[j])
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


//======================================================
//approach 3: top down, dfs + memo
class Solution
{
public:
    std::vector<std::vector<int>> dp;

    int dfs(std::string& s, int i, int j)
    {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == j) return dp[i][j] = 1;

        if (s[i] == s[j])
        {
            dp[i][j] = dfs(s, i + 1, j - 1) + 2;
        }
        else
        {
            dp[i][j] = std::max(dfs(s, i + 1, j), dfs(s, i, j - 1));
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(std::string s)
    {
        int n = s.length();
        dp = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

        return dfs(s, 0, n - 1);
    }
};