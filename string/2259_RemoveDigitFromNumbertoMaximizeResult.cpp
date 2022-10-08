#include <string>

/*
**Intuition**
 check to see if find any digit followed by a bigger number
    - if yes, delete that digit
    - if no, delete the last occurance

**Complexity:**
- Time: O(n)
- Space: O(1)

*/

class Solution
{
public:
    std::string removeDigit(std::string number, char digit)
    {
        int idx = 0;
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] == digit)
            {
                if (i<number.length() - 1 && number[i + 1]>digit)
                {
                    //if found digit followed by a bigger number
                    //remove it
                    idx = i;
                    break;
                }
                else
                {
                    //if did not find digit followed by a bigger number
                    //remove last occurrence
                    idx = i;
                }
            }
        }

        return number.substr(0, idx) + number.substr(idx + 1);
    }
};