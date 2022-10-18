#include <vector>
#include <string>
#include <algorithm>
/*

First approach
This one is conceptually more straightforward. The time complexity is kn^2 x 26, so it's O(kn^2). However the constant of 26 matters and it requires a lot more space to store the states.

This is a top-down approach and we defined the state as dp[i][ch][len][k]:

    - i: current position
    - ch: the character that's in the previous chain
    - len: count of characters in the chain
    - k: how many more characters can we remove

The idea is, consider each character (let's use c to denote the current character) in the string:

1. If we can remove c (when k > 0), we try to remove it. So we can transfer from the state of: dp[i + 1][ch][len][k - 1], note that's k - 1 because we removed c
2. We may also choose to not remove c, there are 2 cases:
    - c is the same as what's in the chain (c == ch). We can transfer from the state of: dp[i + 1][ch][len + 1][k]. ch and len + 1 because it's the same character in the chain and c is added to the length. k remains unchanged because we're not removing the c. 
    - c is different from what's in the chain (c != ch). This effectively means we need to "settle" the previous chain, and start a new chain consists of c. The state transfers from: dp[i + 1][c][1][k] + calcLen(len). c and 1 is the state of the new chain and remember to add calcLen(len), since that's how we settle the length of the previous chain! Again k remains unchanged because we're not removing c.

    
Complexity
Time: 761ms O(kn^2)

Memory: 200MB O(kn^2)

*/

//https://leetcode.com/problems/string-compression-ii/discuss/757506/Detailed-Explanation-Two-ways-of-DP-from-33-to-100
class Solution
{
public:
    int n;
    //int dp[105][27][105][105] inside class give error
    // The variable is too large that it cannot be stored in the stack-memory-area, but it can be stored in the static-memory-area (outside of class).
    //int dp[105][27][105][105];
    std::vector<std::vector<std::vector<std::vector<int>>>> dp;
    int calAbbrLen(const int& len)
    {
        if (len == 0) return 0;
        else if (len == 1)
            return 1;
        else if (len < 10)
            return 2;
        else if (len < 100)
            return 3;

        return 4;
    }

    int solve(int i, int ch, int len, int k, std::string& s)
    {
        if (i == n) return calAbbrLen(len);

        if (dp[i][ch][len][k] != INT_MAX)
        {
            return dp[i][ch][len][k];
        }

        int cur = s[i] - 'a';
        if (k > 0)
        {
            //remove current char
            dp[i][ch][len][k] = solve(i + 1, ch, len, k - 1, s);
        }

        if (cur == ch)
        {
            //current char is same as previous char
            //do not remove current
            //min of remove current and do not remove current char
            dp[i][ch][len][k] = std::min(dp[i][ch][len][k], solve(i + 1, ch, len + 1, k, s));
        }
        else
        {
            //current char is different with previous char
            dp[i][ch][len][k] = std::min(dp[i][ch][len][k],
                calAbbrLen(len) + solve(i + 1, cur, 1, k, s));
            //because it is different char, need to add length of previous char
        }

        return dp[i][ch][len][k];
    }

    int getLengthOfOptimalCompression(std::string s, int k)
    {
        n = s.length();
        dp = std::vector<std::vector<std::vector<std::vector<int>>>>(n, std::vector<std::vector<std::vector<int>>>(27, std::vector<std::vector<int>>(n + 1, std::vector<int>(k + 1, INT_MAX))));

        //bool allSame = true;
        //for (int i = 1; i < n; i++)
        //{
        //    if (s[i] != s[i - 1])
        //    {
        //        allSame = false;
        //        break;
        //    }
        //}

        //if (allSame)
        //{
        //    return calAbbrLen(n - k);
        //}

        return solve(0, 0, 0, k, s);;
    }
};


//optimization on len dimension 
/*
Time complexity: O(26 * 10 * N^2)
Space: O(26 * 10 * N^2)
*/

class Solution_2
{
public:
    int n;
    //int dp[105][27][105][105];
    std::vector<std::vector<std::vector<std::vector<int>>>> dp;
    int calAbbrLen(const int& len)
    {
        if (len == 0) return 0;
        else if (len == 1)
            return 1;
        else if (len < 10)
            return 2;
        else if (len < 100)
            return 3;

        return 4;
    }

    int solve(int i, int ch, int len, int k, std::string& s)
    {
        //int lenCut = min(10,calAbbrLen(len));
        if (i == n) return 0;

        if (dp[i][ch][len][k] != INT_MAX / 2)
        {
            return dp[i][ch][len][k];
        }

        int cur = s[i] - 'a';
        if (k > 0)
        {
            //remove current char
            dp[i][ch][len][k] = solve(i + 1, ch, len, k - 1, s);
        }

        if (cur == ch)
        {
            //current char is same as previous char
            //do not remove current
            //min of remove current and do not remove current char
            const int fac = (len == 1 || len == 9) ? 1 : 0;
            dp[i][ch][len][k] = std::min(dp[i][ch][len][k], fac + solve(i + 1, ch, min(10, len + 1), k, s));
        }
        else
        {
            //current char is different with previous char
            dp[i][ch][len][k] = std::min(dp[i][ch][len][k],
                1 + solve(i + 1, cur, 1, k, s));
            //because it is different char, need to add length of previous char
        }

        return dp[i][ch][len][k];
    }

    int getLengthOfOptimalCompression(std::string s, int k)
    {
        n = s.length();
        dp = std::vector<std::vector<std::vector<std::vector<int>>>>(n, std::vector<std::vector<std::vector<int>>>(27, std::vector<std::vector<int>>(11, std::vector<int>(k + 1, INT_MAX / 2))));

        //for length, instead of using length of string, can be optimized to only 10.
        //because s.length is 100,
        //we don't need a space of 100 for the len part in dp array. because x >= 10 && x <= 99 doesn't increment a length contribution to the total length.
        //However, we need a special check for the case which has 100 same chars.
        bool allSame = true;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                allSame = false;
                break;
            }
        }

        if (allSame)
        {
            return calAbbrLen(n - k);
        }

        return solve(0, 26, 0, k, s);;
    }
};