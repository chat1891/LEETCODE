#include <string>
#include <vector>
#include <iostream>
using namespace std;

 class Solution
{
public:
    int ns = 0;
    int np = 0;

    bool dfs(int i, int j, vector<vector<int>>& memo, string& s, string& p)
    {
        if (i >= ns && j >= np) return true; //s, and j to the end to find match
        if (j >= np) return false; //pattern to the end, failed match
        if (i < ns && memo[i][j] != -1) return memo[i][j];

        bool isMatch = i < ns && (s[i] == p[j] || p[j] == '?');
        //match *
        if (p[j] == '*')
        {
            memo[i][j] = (i < ns&& dfs(i + 1, j, memo, s, p)) //match and try match next
                || (i < ns&& dfs(i + 1, j + 1, memo, s, p)) //match, stop matching
                || dfs(i, j + 1, memo, s, p); //no match
    //when no match, do not check i<ns 
    //for case s = "" and p = "****"
    //ns = 0, if check ns<i = 0<0, it will return false

            return memo[i][j];
        }

        if (isMatch)
        {
            memo[i][j] = dfs(i + 1, j + 1, memo, s, p);
            return memo[i][j];
        }

        return false;


    }
    bool isMatch(string s, string p)
    {
        ns = s.empty() ? 0 : s.length();
        np = p.length();

        vector<vector<int>> memo(ns + 1, vector<int>(np + 1, -1));
        //memo[ns][np]=1;

        return dfs(0, 0, memo, s, p) == 1;
    }
};

//free memory
class Solution
{
public:
    bool f(string& s, string& p, int s_idx, int p_idx, int** dp)
    {
        int* curr = (*(dp + s_idx) + p_idx);  // current cell in table
        // if in dp
        if (*curr != -1)
        {
            return *curr;
        }
        // if both strings covered
        if ((s_idx >= s.length()) && (p_idx >= p.length()))
        {
            *curr = 1;
            return *curr;
        }
        // if p covered
        if (p_idx >= p.length())
        {
            *curr = 0;
            return *curr;
        }
        // if s covered
        if (s_idx >= s.length())
        {
            // check if the rest of p is '*'
            for (int i = p_idx; i < p.length(); i++)
            {
                // if non-'*' found
                if (p[i] != '*')
                {
                    *curr = 0;
                    return *curr;
                }
            }
            // rest of p is '*'
            *curr = 1;
            return *curr;
        }
        // if '*'
        if (p[p_idx] == '*')
        {
            *curr = (f(s, p, (s_idx + 1), p_idx, dp) || f(s, p, s_idx, (p_idx + 1), dp));
            return *curr;
        }
        // if '?' or match
        else if ((p[p_idx] == '?') || (s[s_idx] == p[p_idx]))
        {
            *curr = f(s, p, (s_idx + 1), (p_idx + 1), dp);
            return *curr;
        }
        // else false
        else
        {
            *curr = 0;
            return *curr;
        }
    }

    bool isMatch(string s, string p)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // dynamic programming table
        int** dp = (int**)malloc((s.length() + 1) * sizeof(int*));
        for (int i = 0; i < (s.length() + 1); i++)
        {
            *(dp + i) = (int*)malloc((p.length() + 1) * sizeof(int));
            for (int j = 0; j < (p.length() + 1); j++)
            {
                *(*(dp + i) + j) = -1;  // default value
            }
        }
        bool ans = f(s, p, 0, 0, dp);
        // free dp
        for (int i = 0; i < (s.length() + 1); i++)
        {
            free(*(dp + i));
        }
        free(dp);
        return ans;
    }
};
