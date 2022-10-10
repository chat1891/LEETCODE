#include<string>

class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int base = 26;
        long res = 0;
        long acc = 1;

        for (int i = columnTitle.length() - 1; i >= 0; i--)
        {
            int cur = columnTitle[i] - 'A';
            cur++;
            res += (cur * acc);
            acc *= base;
        }

        return res;
    }
};