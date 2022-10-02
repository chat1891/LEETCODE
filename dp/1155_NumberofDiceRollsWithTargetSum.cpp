#include <vector>
//similar to 332. coin change

class Solution
{
public:
    int mod = 1e9 + 7;
    int dfs(std::vector<std::vector<int>>& memo, int idx, int target, int k, int curSum, int n)
    {
        if (idx == n) return curSum == target;
        if (memo[idx][curSum] != -1) return memo[idx][curSum];

        int count = 0;
        int left = std::min(k, target - curSum);
        for (int i = 1; i <= left; i++)
        {
            count += dfs(memo, idx + 1, target, k, curSum + i, n);
            count %= mod;

        }
        return memo[idx][curSum] = count;

    }
    int numRollsToTarget(int n, int k, int target)
    {
        std::vector<std::vector<int>> memo(n + 1, std::vector<int>(target + 1, -1));
        return dfs(memo, 0, target, k, 0, n);
    }
};