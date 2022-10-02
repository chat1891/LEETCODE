#include <cstdint>
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        uint32_t temp = 0;

        for (int i = 0; i < 32; i++)
        {
            uint32_t temp = 1;
            temp = temp << i;
            int j = 31 - i;
            //because it is symmetric,
            //shift i to the 0 position
            //then shift j to correct position at the end
            //otherwise shift 31-i-i, but after go through half, it out of bound
            uint32_t digit = (temp & n) >> i << j;
            res = res | digit;
        }
        return res;
    }
};