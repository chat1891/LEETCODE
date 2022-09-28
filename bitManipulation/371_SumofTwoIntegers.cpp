#include <string>

class Solution_unsignedInt
{
public:
    // 011  3
    //+101  5
    //1000  8
    int getSum(int a, int b)
    {
        // (a^b) basically gives sum of two integers directly(try returning a^b to sample test case) but we need to deal with carry 

       // So here is the deal: we are storing value of a&b to carry: that is if there are set-bits at one position in a as well as b
       //carry will be 1 and a will store a^b, if we have set-bits in both integers, then their xor will actually 
       // return 0 and carry 1 to one position left. Then b is processing that for the next step, by left-shifting all the positions where both are 
       // set-bits so that we can add those to our ans(a here) in the next step
       // we will repeat procedure till b(or carry) becomes zero
        while (b != 0)
        {
            //* unsigned int because a or b can be negative 
            //and we cannot do left-shifts to negative integers. Unsigned int is always +ve
            unsigned int carry = (a & b); //101 & 011 =001, get the carry
            //keep digits that needs to add but not carrying, a=101 ^ 011 =110
            //also 1+1 = 0
            a = a ^ b;

            b = carry << 1;
        }

        return a;
    }
};

class Solution_uint32_t
{
public:
    // 011  3
    //+101  5
    //1000  8
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            //*use (uint32_t) to work with negative numbers
            int carry = (uint32_t)(a & b); //101 & 011 =001, get the carry
            //keep digits that needs to add but not carrying, a=101 ^ 011 =110
            //also 1+1 = 0
            a = a ^ b;
            //*use (uint32_t) to work with negative numbers
            b = (uint32_t)carry << 1;
        }

        return a;
    }
};