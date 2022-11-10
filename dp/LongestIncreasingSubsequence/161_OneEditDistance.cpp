#include <stdlib.h>
#include <string>

//time:O(N)
// SPACE O(1)
//this approach didn't use substring, because substring is expensive, it is copying the string O(n)
class Solution
{
public:
    bool isOneEditDistance(std::string s, std::string t)
    {
        int sl = s.length();
        int tl = t.length();
        if (abs(tl - sl) > 1)
            return false;
        // keep shorter string as 's'
        if (sl > tl) return isOneEditDistance(t, s);

        int diff = 0;
        int j = 0;
        if (sl == tl)
        {
            //same length, can only replace
            for (int i = 0; i < sl; i++)
            {
                if (s[i] != t[j])
                {
                    diff++;
                }
                j++;
                if (diff > 1) return false;
            }
        }
        else
        {
            //different length, for one change: either delete or insert
            for (int i = 0; i < sl; i++)
            {
                if (s[i] != t[j])
                {
                    diff++;
                    // when characters of 1 length different string mismatch,
                    // try comparing next character from longer string with same character from 's' string
                    i--;
                    if (diff > 1)
                        return false;
                }
                j++;
            }
            //for case ab, abc
            //matched ab, but still need to count missing c as one operation
            if (j <= tl)
                diff += (sl - j + 1);
        }

        //if diff==0, return false
        return diff == 1;
    }
};