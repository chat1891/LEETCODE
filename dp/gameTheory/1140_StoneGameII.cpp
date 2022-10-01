#include <vector>
#include <numeric> 


//time complexity O(n^3)
//space complexity O(n^2)
class Solution
{
public:
    int n;
    int helper(std::vector<int>& piles, std::vector<std::vector<int>>& memo, std::vector<int>& sum, int start, int M)
    {
        if (start == n - 1) return piles[start];
        if (memo[start][M] != -1) return memo[start][M];

        //if M> number of piles left, take the suffix sum directly
        if (n - start <= 2 * M) return sum[start];

        int ans = INT_MAX;
        //can take minimum 1, maximum 2M piles
        for (int i = 1; i <= 2 * M; i++)
        {
            //to minimize opponent's choice
            ans = std::min(ans, helper(piles, memo, sum, start + i, std::max(M, i)));
        }

        //result is (sum - opponent's score)
        return memo[start][M] = sum[start] - ans;
    }

    int stoneGameII(std::vector<int>& piles)
    {
        n = piles.size();

        //calculate suffix sum        
        std::vector<int> sum(n);
        sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            sum[i] = piles[i] + sum[i + 1];
        }

        //<start index,M>
        std::vector<std::vector<int>> memo(n, std::vector<int>(2 * n, -1));
        return helper(piles, memo, sum, 0, 1);
    }
};

//https://wingkwong.github.io/leetcode-the-hard-way/
//https://github.com/wingkwong?tab=repositories
class Solution_2
{
public:
    // dp[i][j] = max stones you can get from piles[i:] with M = j
    int dp[101][200], n;
    int dfs(std::vector<int>& piles, int i, int m, int total)
    {
        // if we calculated the result before, use it directly
        if (dp[i][m] != -1) return dp[i][m];
        // res: used to compare the max number of stones
        // taken: used to record how many stones we've taken
        int res = 0, taken = 0;
        // i is the starting position
        // we can take at most i + 2 * m piles
        // however, it may exceed the size of piles 
        // hence use min to get the max limit
        for (int j = i; j < std::min(i + 2 * m, n); j++)
        {
            // take this pile of stones
            taken += piles[j];
            // move to the next position
            // with the new M = max(M, X)
            // where X is how many piles we've taken so far which is j - i + 1
            res = std::max(res, total - dfs(piles, j + 1, std::max(m, j - i + 1), total - taken));
        }
        // memoize the result
        return dp[i][m] = res;
    }

    int stoneGameII(std::vector<int>& piles)
    {
        // init dp with value -1
        memset(dp, -1, sizeof(dp));
        n = piles.size();
        return dfs(piles, 0, 1, accumulate(piles.begin(), piles.end(), 0));
    }
};