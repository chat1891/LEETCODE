#include <vector>
#include <string>
using namespace std;
//not sure how to do space optimization
//https://leetcode.com/problems/distinct-subsequences/discuss/2024556/C%2B%2B-DP-Solution-(Recursive-Top-Down-Bottom-Up-Space-Optimized)
//https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)


//https://www.youtube.com/watch?v=-RDzMJ33nx8
//recursive

class Solution
{
public:
    int ns = 0;
    int nt = 0;
    int dfs(string& s, string& t, int i, int j, vector<vector<int>>& dp)
    {
        if (i == ns && j < nt)
        {
            //s="" and t = a
            return 0;
        }
        //s=a and t=""
        if (j == nt) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int count = 0;
        if (s[i] == t[j])
        {
            count += dfs(s, t, i + 1, j + 1, dp);
            count += dfs(s, t, i + 1, j, dp);

        }
        else
        {
            count += dfs(s, t, i + 1, j, dp);
        }

        return dp[i][j] = count;

    }

    int numDistinct(string s, string t)
    {
        ns = s.length();
        nt = t.length();
        vector<vector<int>> dp(ns, vector<int>(nt, -1));
        return dfs(s, t, 0, 0, dp);

    }
};

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int ns = s.length();
        int nt = t.length();

        //use unsigned int to avoid overflow
        vector<vector<unsigned int>> dp(ns + 1, vector<unsigned int>(nt + 1, 0));
        //base case
        for (int i = ns; i >= 0; i--)
        {
            dp[i][nt] = 1;
        }
        for (int j = nt - 1; j >= 0; j--)
        {
            dp[ns][j] = 0;
        }

        for (int i = ns - 1; i >= 0; i--)
        {
            for (int j = nt - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
};