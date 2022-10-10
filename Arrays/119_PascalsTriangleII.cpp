#include <vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0) return { 1 };
        std::vector<int> prev = { 1,1 };
        if (rowIndex == 1) return prev;
        std::vector<int> cur;

        for (int r = 2; r <= rowIndex; r++)
        {
            cur.clear();
            for (int i = 0; i <= r; i++)
            {
                if (i == 0 || i == r)
                {
                    cur.push_back(1);
                }
                else
                {
                    cur.push_back(prev[i - 1] + prev[i]);
                }

            }
            prev = cur;
        }
        return cur;

    }
};