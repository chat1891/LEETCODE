#include <string>
#include <unordered_set>

//similar to 828 count Unique Characters of All Substrings of a Given String
//similar to 2262 Total Appeal of A String

class Solution
{
public:
    long long countVowels(std::string word)
    {
        std::unordered_set<char> vowels{ 'a','e','i','o','u' };
        long long res = 0;
        long long n = word.size();
        for (long long i = 0; i < n; i++)
        {
            char c = word[i];
            if (vowels.find(c) != vowels.end())
            {
                res += (i + 1) * (n - i);
            }
        }
        return res;
    }
};