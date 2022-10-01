//same as LC 486]
#include <vector>

class Solution
{
    //time complexity is O(n^2)
    //because how many start, end combination we can get
    //n *n = n possibilities for start, and n for end
public:
    int helper(std::vector<int>& piles, std::vector<std::vector<int>>& memo, int s, int e)
    {
        if (s == e)
        {
            return piles[s];
        }
        if (memo[s][e] != -1) return memo[s][e];

        //deduct opponent's score
        memo[s][e] = std::max(piles[s] - helper(piles, memo, s + 1, e),
            piles[e] - helper(piles, memo, s, e - 1));

        return memo[s][e];
    }

    bool stoneGame(std::vector<int>& piles)
    {
        int  n = piles.size();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));

        //if want to get how many score of each player
        //we know x+y= sum
        //we know x-y = helper func gives
        //so we can calculate x and y

        return helper(piles, memo, 0, n - 1) > 0;
    }
};


class Solution
{
public:
    int helper(std::vector<int>& piles, std::vector<std::vector<int>>& memo, int s, int e, int turn)
    {
        if (s == e)
        {
            return turn * piles[s];
        }
        if (memo[s][e] != -1) return memo[s][e];

        if (turn > 0)
        {
            memo[s][e] = std::max(turn * piles[s] + helper(piles, memo, s + 1, e, turn * -1),
                turn * piles[e] + helper(piles, memo, s, e - 1, turn * -1));
        }
        else
        {
            memo[s][e] = std::min(turn * piles[s] + helper(piles, memo, s + 1, e, turn * -1),
                turn * piles[e] + helper(piles, memo, s, e - 1, turn * -1));
        }
        return memo[s][e];
    }

    bool stoneGame(std::vector<int>& piles)
    {
        int  n = piles.size();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));

        return helper(piles, memo, 0, n - 1, 1) > 0;
    }
};