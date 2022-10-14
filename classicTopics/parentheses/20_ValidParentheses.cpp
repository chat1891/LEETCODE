#include <stack>
#include <string>

//method 1 use stack
//if find open bracket
//add close bracket to the stack
//check if stack is empty or if it is not equal to top, then return false
//at end return of stack is empty
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stk;
        for (auto& c : s)
        {
            if (c == '(')
            {
                stk.push(')');
            }
            else if (c == '[')
            {
                stk.push(']');
            }
            else if (c == '{')
            {
                stk.push('}');
            }
            else
            {
                if (stk.empty() || c != stk.top())
                {
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();
    }
};

//method 2
//use stack
//if find open bracket, add to stack
//if find a non open bracket, check previous in stack, and check if current will match previous one
//at end return of stack is empty
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stk;
        for (auto& c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stk.push(c);
            }
            else if (!stk.empty())
            {
                char pre = stk.top();
                stk.pop();
                if (pre == '(' && c != ')') return false;
                if (pre == '[' && c != ']') return false;
                if (pre == '{' && c != '}') return false;

            }
            else
            {
                return false;
            }
        }

        return stk.empty();
    }
};