#include<string>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        int na = a.length();
        int nb = b.length();
        int ia = na - 1, ib = nb - 1, carry = 0;
        std::string res;

        while (ia >= 0 || ib >= 0 || carry > 0)
        {
            if (ia >= 0)
            {
                carry += (a[ia] - '0');
                ia--;
            }

            if (ib >= 0)
            {
                carry += (b[ib] - '0');
                ib--;
            }

            //if a and b are 1, carry = 2, mod is 0
            //carry /2 = 1
            res = std::to_string(carry % 2) + res;
            carry /= 2;
        }

        return res;
    }
};