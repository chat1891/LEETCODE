#include <string>

//same as LEETCODE 5 Longest Palindromic Substring
class Solution
{
public:
    int n;
    int res = 0;
    void checkPalindrome(std::string& s, int left, int right)
    {
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--; //trace left direction
            right++; //trace right direction
            res++; //increment count if found palindrome
        }

    }
    int countSubstrings(std::string s)
    {
        n = s.length();
        for (int i = 0; i < n; i++)
        {
            checkPalindrome(s, i, i); //if length is odd
            checkPalindrome(s, i, i + 1); //if length is even
        }

        return res;
    }
};


//============================================
//approach 2: dp
class Solution
{
public:
    int countSubstrings(std::string s)
    {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int res = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 2 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                    }
                }
                if (dp[i][j]) res++;
            }
        }

        return res;
    }
};