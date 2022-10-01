#include <vector>
#include <string>

//time O(ns * np)
class Solution_dp
{
    //https://www.youtube.com/watch?v=HAA8mgxlov8
public:
    int ns = 0;
    int np = 0;

    bool dfs(int i, int j, std::vector<std::vector<int>>& memo, const std::string& s, const std::string& p)
    {
        if (i < ns && j < np && memo[i][j] != -1) return memo[i][j];
        if (i >= ns && j >= np) return true; //both s and p reach to the end
        if (j >= np) return false; //s is not at end, but p is

        //take care of . and exact match
        bool match = (i < ns && (s[i] == p[j] || p[j] == '.'));

        //if there is a * -> take care of *
        if ((j + 1) < np && p[j + 1] == '*')
        {
            memo[i][j] = ((match && dfs(i + 1, j, memo, s, p)) //use *
                || dfs(i, j + 2, memo, s, p)); // do not use *
            return memo[i][j];
        }

        //if no * and matched -> move to next digit
        if (match)
        {
            memo[i][j] = dfs(i + 1, j + 1, memo, s, p);
            return memo[i][j];
        }

        return false;

    }

    bool isMatch(std::string s, std::string p)
    {
        ns = s.length();
        np = p.length();
        //need to give one extra to avoid overflow
        std::vector<std::vector<int>> memo(ns + 1, std::vector<int>(np + 1, -1));
        return dfs(0, 0, memo, s, p);
    }
};

//no dp
//brute force
class Solution_bruteForce
{
    //https://www.youtube.com/watch?v=HAA8mgxlov8
public:
    int ns = 0;
    int np = 0;

    bool dfs(int i, int j, const std::string& s, const std::string& p)
    {
        if (i >= ns && j >= np) return true; //both s and p reach to the end
        if (j >= np) return false; //s is not at end, but p is

        //take care of . and exact match
        bool match = (i < ns && (s[i] == p[j] || p[j] == '.'));

        //if there is a * -> take care of *
        if ((j + 1) < np && p[j + 1] == '*')
        {
            return ((match && dfs(i + 1, j, s, p)) //use *
                || dfs(i, j + 2, s, p)); // do not use *              
        }

        //if no * and matched -> move to next digit
        if (match)
        {
            return dfs(i + 1, j + 1, s, p);
        }

        return false;

    }

    bool isMatch(std::string s, std::string p)
    {
        ns = s.length();
        np = p.length();
        //need to give one extra to avoid overflow
        return dfs(0, 0, s, p);
    }
};