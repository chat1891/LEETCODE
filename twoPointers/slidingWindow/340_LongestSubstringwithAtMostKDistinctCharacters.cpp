#include <string>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k)
    {
        //sliding window
        std::unordered_map<char, int> freq;
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++)
        {
            char cur = s[right];
            //add char to frequency map
            freq[cur]++;

            //if have more than k distinct character
            //pop from left side
            while (freq.size() > k)
            {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                {
                    freq.erase(s[left]);
                }
                left++;
            }
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};