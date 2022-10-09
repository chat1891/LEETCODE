#include <string>
#include <iostream>
class Solution
{
public:
    bool isValid(std::string s, int numDecimal)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == '+' || s[i] == '-') && i != 0)
            {
                //+,- needs to be at beginning
                return false;
            }
        }

        int pos = 0;
        if ((s[0] == '+' || s[0] == '-'))
        {
            pos++; //skip the +-
            //then whatever left is decimal number
        }

        //if only left . or it is empty return false
        //"e", "e."
        if (s.substr(pos) == "" || s.substr(pos) == ".")
        {
            return false;
        }

        //verify decimal number
        int countDot = 0;
        for (int i = pos; i < s.length(); i++)
        {
            if (s[i] == '.')
            {
                countDot++;
            }
            else if (!isdigit(s[i]))
            {
                return false;
            }
        }
        return countDot <= numDecimal;

    }

    bool isNumber(std::string s)
    {
        //remove empty space
        while (!s.empty() && s[0] == ' ')
        {
            s.erase(s.begin());
        }
        while (!s.empty() && s[s.size() - 1] == ' ')
        {
            s.pop_back();
        }

        if (s.empty())
            return false;

        int countE = 0;
        int pos;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                countE++;
                pos = i;
            }
        }
        //[+a] e [+b]
        if (countE > 1) return false;
        if (countE == 0) return isValid(s, 1);
        if (countE == 1) return isValid(s.substr(0, pos), 1)
            && isValid(s.substr(pos + 1), 0);

        return false;
    }
};