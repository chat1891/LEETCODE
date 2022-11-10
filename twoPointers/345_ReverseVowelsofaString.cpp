#include <string>
#include <unordered_set>
#include <sstream>
class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        std::unordered_set<char> vowels = { 'a','e','i','o','u','A','E','I','O','U' };

        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            while (l < r && vowels.count(s[l]) == 0)
            {
                l++;
            }
            while (l < r && vowels.count(s[r]) == 0)
            {
                r--;
            }

            if (l < r)
            {
                std::swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};