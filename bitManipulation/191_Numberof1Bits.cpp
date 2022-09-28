#include <string>


//Approach 1: Loop and Flip
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};

//bit manipulation
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};