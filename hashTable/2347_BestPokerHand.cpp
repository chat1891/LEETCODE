#include <unordered_map>
#include <string>

class Solution
{
public:
    std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits)
    {
        std::unordered_map<char, int> s2r; //suit, count
        std::unordered_map<int, int> r2s; //rank, count
        int n = ranks.size();

        for (int i = 0; i < n; i++)
        {
            s2r[suits[i]]++;
            r2s[ranks[i]]++;
        }

        for (auto& suit : s2r)
        {
            if (suit.second >= 5)
            {
                return "Flush";
            }
        }

        bool hasPair = false;
        for (auto& rank : r2s)
        {
            if (rank.second >= 3)
            {
                return "Three of a Kind";
            }

            if (rank.second == 2) hasPair = true;
        }
        if (hasPair) return "Pair";
        return "High Card";
    }
};