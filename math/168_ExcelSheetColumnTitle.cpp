#include<string>

class Solution
{
public:
    std::string convertToTitle(int columnNumber)
    {
        int base = 26;
        std::string res;
        while (columnNumber)
        {
            columnNumber--;//0 is A, 25 is Z
            char cur = 'A' + (columnNumber % base);
            res = cur + res;
            columnNumber /= base;
        }

        return res;
    }
};