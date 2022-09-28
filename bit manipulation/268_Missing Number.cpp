#include <vector>
using namespace std;

class Solution_bitManupulation
{
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int miss = 0;
        for (auto num : nums)
        {
            miss ^= num;
        }

        for (int i = 0; i <= n; i++)
        {
            //xor twice will elimimate the number
            //it already xor_ed once for all the numbers
            //whatever left is the result
            miss ^= i;
        }

        return miss;
    }
};

//Arithmetic Sequence
//Approach #4 Gauss' Formula [Accepted]
class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int sum = (1 + n) * (n) / 2;
        for (auto num : nums)
        {
            sum -= num;
        }
        return sum;
    }
};

