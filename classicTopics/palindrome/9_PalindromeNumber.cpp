#include <string>

/*
only need to consider half of digits

length is odd:
12321
1232 1
123 12
12 123
12 ==(123/12) cut last number

length is even
1221
122 1
12 12
12 == 12

*/

//this method also avoid overflow problem
//Time O(log_10(n))
//space O(1)

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int reversed = 0;
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return(reversed == x || x == reversed / 10);
    }
};


//==================================================
//approach 2, reverse entire number and compare
//Time O(log_10(n))
//space O(1)
class Solution
{
public:
    bool isPalindrome(int x)
    {
        //negative num or last digit is 0
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }

        long reversed = 0;//might overflow when reversed
        int x2 = x;
        while (x2)
        {
            reversed = reversed * 10 + x2 % 10;
            x2 /= 10;
        }
        return reversed == x;
    }
};

//===============================================
//approach 3 convert to string then use two pointer
//Time O(n)
//space O(1)
class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string str = std::to_string(x);
        int p1 = 0;
        int p2 = str.length() - 1;
        while (p1 <= p2)
        {
            if (str[p1] == str[p2])
            {
                p1++;
                p2--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};