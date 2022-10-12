#include <string>

/*
        "0 0 0 0 1 1 1 0 0 1 1"
index:   0 1 2 3 4 5 6 7 8 9 10

group 1: form i=0 to 6 -> 0000111
        prev = 4 zeros, cur = 3 ones
        combination is 0[0[0[01]1]1], so min of (prev, cur) = 3

group 2: use previous ones, so prev = cur;
        from i=4 to 8 -> 1 [1 [1 0] 0]
        prev = 3 ones, cur = 2 zeros
        min of (prev, cur) = 2

group 3: form i=7 to 10 -> 0000111
        prev = 2 zeros, cur = 2 ones
        combination is [0 [0 1] 1], so min of (prev, cur) = 2


Complexity:
- time: O(n)
- space: O(1)

*/

class Solution
{
public:
    int countBinarySubstrings(std::string s)
    {
        int res = 0;
        int prev = 0;
        int cur = 1; //count of continuous 1s or 0s
        int n = s.length();



        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] != s[i])
            {
                res += std::min(cur, prev);
                prev = cur;
                cur = 1;
            }
            else
            {
                cur++;
            }
        }

        return res + std::min(cur, prev);
    }
};