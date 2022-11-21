#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

/*
Time O(n logn)
space O(n)

*/
class Solution
{
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
    {
        std::unordered_map<int, int> mp; //player, num of lost matches
        std::unordered_set<int> players;

        for (auto& match : matches)
        {
            players.insert(match[0]);
            players.insert(match[1]);

            mp[match[1]]++;
        }

        std::vector<std::vector<int>> ans;
        std::vector<int> ans0;
        std::vector<int> ans1;
        for (auto& player : players)
        {
            if (mp.count(player) == 0)
            {
                ans0.push_back(player);
            }
            else if (mp[player] == 1)
            {
                ans1.push_back(player);
            }
        }

        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        ans.push_back(ans0);
        ans.push_back(ans1);
        return ans;

    }
};

//Counting with Array
//counting sort
//no sort
//Time O(n+k)
//space O(k)
/*
losses_count[i] = -1, player i has not played.
losses_count[i] = 0, player i has played at least one game and has 0 loss.
losses_count[i] = 1, player i has exact 1 loss.
losses_count[i] > 1, player i has more than 1 loss.

Algorithm
- Use an array losses_count to store the number of losses for each player. Initially, losses_count[i] = -1 for every index i.
- For each match [winner, loser]:
    - If losses_count[loser] = -1, set it to 1, otherwise increment it by 1.
    - If losses_count[winner] = -1, set it to 0.
- Iterate over losses_count and use two arrays to store these 2 kinds of players, for each index i:
    - If losses_count[i] = 0, add this player to the first array.
    - If losses_count[i] = 1, add this player to the second array.
*/
class Solution
{
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
    {
        std::vector<int> lossesCount(100001, -1);

        for (auto& match : matches)
        {
            int& winner = match[0]; int& loser = match[1];
            if (lossesCount[winner] == -1)
            {
                lossesCount[winner] = 0;
            }

            if (lossesCount[loser] == -1)
            {
                lossesCount[loser] = 1;
            }
            else
            {
                lossesCount[loser]++;
            }
        }

        std::vector<std::vector<int>> ans;
        std::vector<int> ans0;
        std::vector<int> ans1;
        for (int i = 0; i < 100001; i++)
        {
            if (lossesCount[i] == 0)
            {
                ans0.push_back(i);
            }
            else if (lossesCount[i] == 1)
            {
                ans1.push_back(i);
            }
        }

        ans.push_back(ans0);
        ans.push_back(ans1);
        return ans;
    }
};