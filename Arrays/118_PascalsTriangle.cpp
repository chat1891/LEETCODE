#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> res;
        res.push_back({ 1 });
        if (numRows == 1) return res;
        res.push_back({ 1,1 });
        if (numRows == 2) return res;

        for (int level = 3; level <= numRows; level++)
        {
            std::vector<int> cur;
            std::vector<int>& prev = res[level - 2];
            for (int i = 0; i < level; i++)
            {
                //start and end is 1
                if (i == 0 || i == level - 1)
                {
                    cur.push_back(1);
                }
                else
                {
                    int num = prev[i] + prev[i - 1];
                    cur.push_back(num);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};