#include <string>
#include <stack>

/*
method 1 two pass
- from left to right, check valid ")"
- from right to left, check valid "("
- if count left == count right, size=2*count
- if not equal, reset counts
*/

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        int countL = 0;
        int countR = 0;
        int n = s.length();
        int res = 0;
        //from left to right, check valid ")"
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                countL++;
            }
            else
            {
                countR++;
            }

            if (countL == countR)
            {
                res = std::max(countL * 2, res);
            }
            else if (countR > countL)
            {
                countL = 0;
                countR = 0;
            }
        }

        countL = 0;
        countR = 0;
        //from right to left, check valid "("
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                countL++;
            }
            else
            {
                countR++;
            }

            if (countL == countR)
            {
                res = std::max(countL * 2, res);
            }
            else if (countL > countR)
            {
                countL = 0;
                countR = 0;
            }
        }

        return res;

    }
};


/*
method 2 use stack
- if is "(", push idx to stack
- if is ")",
    - if stack not empty, means still have "(", calculate the length
    - else, reset the index
*/

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        std::stack<int> stk;
        int n = s.length();
        int res = 0;
        stk.push(-1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                //pop out previous open parenthesis
                stk.pop();
                if (!stk.empty())
                {
                    //because it popped the previous open
                    //this is the previous invalid position
                    int len = i - stk.top();
                    res = std::max(len, res);

                }
                else
                {
                    stk.push(i);
                }
            }
        }

        return res;
    }
};