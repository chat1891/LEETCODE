#include <string>

/*
a [d (c b c)] a
delete left which is d: check (c b c) is palindrome

a c [(b b) e] c a
delete right which is e, check if (b,b) is palindrome
*/

//Time O(n)
//Space O(1)
class Solution
{
public:
    bool isPan(std::string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(std::string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l < r && s[l] == s[r])
        {
            l++;
            r--;
        }
        //for length is even, need to have >
        //this means no need to delete anything
        if (l >= r)
            return true;

        //either delete left or right character
        return isPan(s, l + 1, r) || isPan(s, l, r - 1);

    }
};