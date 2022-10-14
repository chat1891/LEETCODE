#include <string>
#include <stack>

//every value in stack is previous level's score sum
//every time find a left bracket, start a new level
//when find a right bracket, calculate current level's score, then add previous score
class Solution
{
public:
    int scoreOfParentheses(std::string s)
    {
        std::stack<int> stk;
        stk.push(0);
        for (auto& c : s)
        {
            if (c == '(')
            {
                stk.push(0);
            }
            else
            {
                int curBracket = stk.top();
                stk.pop();
                int previous = stk.top();
                stk.pop();
                int score = previous + std::max(2 * curBracket, 1);
                stk.push(score);
            }
        }

        return stk.top();
    }
};


//use stack
//stack saves score of previous level before open bracket 
//when find a close bracket, score = prev level *2 + the score before previous level

class Solution
{
public:
    int scoreOfParentheses(std::string s)
    {
        int cur = 0;
        std::stack<int> stk;
        for (auto& c : s)
        {
            if (c == '(')
            {
                stk.push(cur);
                cur = 0;
            }
            else
            {
                int curLevel = std::max(2 * cur, 1);
                int prev = stk.top();
                cur = curLevel + prev;
                stk.pop();
            }
        }

        return cur;
    }
};