#include <string>
#include <sstream>
#include <stack>


//use stack
class Solution
{
public:
    std::string removeDuplicates(std::string s)
    {
        std::string res;
        int len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (len != 0 && res[len - 1] == s[i])
            {
                res.pop_back();
                len--;
                continue;
            }
            res += s[i];
            len++;
        }

        return res;
    }
};

//==================================
class Solution
{
public:
    std::string removeDuplicates(std::string s)
    {
        std::stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (!stk.empty() && stk.top() == s[i])
            {
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }

        std::stringstream ss;
        while (!stk.empty())
        {
            ss << stk.top();
            stk.pop();
        }
        std::string res = ss.str();
        reverse(res.begin(), res.end());
        return res;
    }
};