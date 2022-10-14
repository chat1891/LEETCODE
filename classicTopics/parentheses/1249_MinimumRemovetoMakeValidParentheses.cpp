#include <string>
#include <unordered_set>
#include <stack>
#include <sstream>

/*
**method 1**
- find all the invalid then delete them later
    -if find open bracket, add to stack
    - if find close bracket,
        -if still have open bracket in stack, pop stack
        - if not, add to remove list
- add whatever left in stack to remove list
- pass again to delete them
*/


class Solution
{
public:
    std::string minRemoveToMakeValid(std::string s)
    {
        std::stack<int> stk;
        std::unordered_set<int> toRemove;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (stk.empty())
                {
                    toRemove.insert(i);
                }
                else
                {
                    stk.pop();
                }
            }
            else if (s[i] == '(')
            {
                stk.push(i);
            }
        }

        //if there are open brackets left, add them to remove list
        //because they are not valid too
        while (!stk.empty())
        {
            toRemove.insert(stk.top());
            stk.pop();
        }

        std::stringstream res;
        for (int i = 0; i < s.length(); i++)
        {
            if (toRemove.find(i) == toRemove.end())
            {
                res << s[i];
            }
        }

        return res.str();
    }
};


/*
* method2: two pass
- from left to right to remove invalid close brackets
- from right to left to remove invalid left brackets

*/
class Solution
{
public:
    std::string minRemoveToMakeValid(std::string s)
    {
        std::string left;
        int count = 0;
        //from left to right, remove invalid ")"
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                //if find extra close bracket, dont add it
                if (count == 0) continue;
                count--;
            }
            left += s[i];
        }

        count = 0;
        std::string res;
        //from right to left, remove invalid "("
        for (int i = left.length() - 1; i >= 0; i--)
        {
            if (left[i] == ')')
            {
                count++;
            }
            else if (left[i] == '(')
            {
                if (count == 0) continue;
                count--;
            }
            res += left[i];
        }
        reverse(res.begin(), res.end());
        return res;

    }
};