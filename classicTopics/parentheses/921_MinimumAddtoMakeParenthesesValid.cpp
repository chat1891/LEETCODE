#include <string>

//if find a open bracket, open count++
//if find a close bracket, if open count ==0, means need to add one, so close count ++
//return open+close
class Solution
{
public:
    int minAddToMakeValid(std::string s)
    {
        int open = 0;
        int close = 0;
        for (auto& c : s)
        {
            if (c == '(')
            {
                open++;
            }
            else if (c == ')')
            {
                if (open > 0)
                {
                    //still have open parentheses
                    open--;
                }
                else
                {
                    //if run out of open parentheses
                    //need add one open parentheses
                    close++;
                }
            }
        }

        //whatever left in open is number of open paranthese didn't get closed
        //need to add same number of close paranthese
        return close + open;
    }
};