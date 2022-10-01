#include<vector>
#include<string>

//recursion
class Solution_recursion
{
public:
    int n;
    int dfs(std::vector<int>& memo, std::string& str, int index)
    {
        if (index == str.length())
        {
            return 1;
        }

        if (memo[index] != -1)
        {
            return memo[index];
        }

        if (str[index] == '0') return 0;
        if (index == str.length() - 1) return 1;

        int count = dfs(memo, str, index + 1);
        if (index + 2 <= n && stoi(str.substr(index, 2)) <= 26)
        {
            count += dfs(memo, str, index + 2);
        }

        return memo[index] = count;


    }

    int numDecodings(std::string s)
    {
        n = s.length();
        std::vector<int> memo(n + 1, -1);
        return dfs(memo, s, 0);
    }
};



//iterative
class Solution_iterative
{
public:
    int numDecodings(std::string s)
    {
        int len = s.length();
        int count = 0;
        //unordered_map<int,int> checkedValues;

        if (std::stoi(s.substr(0, 1)) == 0)
            return 0;

        if (len == 1)
        {
            return 1;
        }
        std::vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = s[1] == '0' ? 0 : 1;

        for (int i = 2; i <= len; i++)
        {
            int currentDigit = stoi(s.substr(i - 1, 1));
            int doubleDigit = stoi(s.substr(i - 2, 2));
            if (currentDigit >= 1)
            {
                dp[i] += dp[i - 1];
            }

            if (doubleDigit >= 10 && doubleDigit <= 26)
            {
                dp[i] += dp[i - 2];
            }

        }
        return dp[len];
    }
};