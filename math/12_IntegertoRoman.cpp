#include <string>
#include <sstream>
#include <vector>
class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::vector<int> values{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        std::vector<std::string> symbols{ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

        std::stringstream ss;
        for (int i = 0; i < values.size() && num>0; i++)
        {
            while (values[i] <= num)
            {
                num -= values[i];
                ss << symbols[i];
            }
        }

        return ss.str();
    }
};