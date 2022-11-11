#include <string>
#include <vector>


class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::vector<int> freq(26); //char, freq
        if (s.length() != t.length())
            return false;

        for (auto& c : s)
        {
            freq[c - 'a']++;
        }
        for (auto& c : t)
        {
            if (freq[c - 'a'] != 0)
            {
                freq[c - 'a']--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};