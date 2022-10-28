#include <string>
#include <unordered_map>
#include <sstream>

/// <summary>
/// bucket sort
/// time: O(n)
/// </summary>
class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        int n = s.length();
        std::unordered_map<char, int> mp;
        for (auto& c : s) mp[c]++;

        std::vector<std::vector<char>> buckets(n + 1); //store frequency
        for (auto& item : mp)
        {
            //add char to correct frequency slot
            buckets[item.second].push_back(item.first);
        }

        std::stringstream ss;
        for (int i = n; i >= 0; i--)
        {
            for (auto& c : buckets[i])
            {
                for (int j = 0; j < i; j++)
                    ss << c;
            }
        }
        return ss.str();
    }
};