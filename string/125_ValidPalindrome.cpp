#include <ctype.h>
#include <string>

class Solution
{
public:
    bool isValid(char& s1)
    {
        return isalpha(s1) || isdigit(s1);
    }

    bool isPalindrome(std::string s)
    {
        int l = 0;
        int n = s.length();
        int r = n - 1;
        while (l <= r)
        {
            if (!isValid(s[l]))
            {
                l++;
                continue;
            }
            if (!isValid(s[r]))
            {
                r--;
                continue;
            }

            if (toupper(s[l]) != toupper(s[r]))
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};