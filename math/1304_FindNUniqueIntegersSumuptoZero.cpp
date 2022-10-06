#include <vector>

class Solution
{
public:
    std::vector<int> sumZero(int n)
    {
        std::vector<int> res(n);
        int left = 0;
        int right = n - 1;
        int val = 1;
        while (left < right)
        {
            res[left++] = (-1) * val;
            res[right--] = val;
            val++;
        }
        return res;
    }
};