#include<string>

/*
Intuition
division by two is the same as the right shift by one bit (character). If the bit is 0, we just do the shift - one operation.

If the bit is 1 - we do plus one, and our bit changes to zero. So, we set carry to 1 and shift. Two operations.

Complexity
    Time: O(N)
    Space O(1)

*/

class Solution
{
public:
    int numSteps(std::string s)
    {
        int count = 0;
        int carry = 0;

        //do not evaluate s[0]
        for (int i = s.length() - 1; i > 0; i--)
        {
            if ((s[i] - '0' + carry) == 1)
            {
                //is odd: operation 1 : +1
                //carry = 1;
                //after =1,  becomes even, operation 2: divide by 2
                count += 2;
                carry = 1;
            }
            else
            {
                //if it is even
                //divide by 2
                count++;
            }
        }

        //when have last digit left,
        //if have carry left, add the carry becomes 0, one operation divide by 2
        //if no carry left, then only 1 left, no further operation
        return count + carry;
    }
};