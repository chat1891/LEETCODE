#include <string>

//use rolling state
//if it is open parentheses, depth++
//if close parentheses, depth--

class Solution
{
public:
    int maxDepth(std::string s)
    {
        int res = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                depth++;
                res = std::max(res, depth);
            }
            else if (s[i] == ')')
            {
                depth--;
            }
        }

        return res;
    }
};