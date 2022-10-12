#include <vector>
#include <string>

//Time: O(n)
//Space: O(n)
class Solution
{
public:
    int minFlipsMonoIncr(std::string s)
    {
        int n = s.length();
        //from i to n-1, min number of flips to change all to 1
        std::vector<int> r(n);
        //from 0 to i, min number of flips to change all to 0
        std::vector<int> l(n);

        l[0] = s[0] - '0';
        r[n - 1] = '1' - s[n - 1];

        for (int i = 1; i < n; i++)
        {
            l[i] = l[i - 1] + (s[i] - '0');
        }

        for (int i = n - 2; i >= 0; i--)
        {
            r[i] = r[i + 1] + ('1' - s[i]);
        }

        int res = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            //l[i-1] : put first i-1 to 0
            //r[i]: put from i to n-1 to 1
            res = std::min(res, l[i - 1] + r[i]);
        }

        res = std::min(res, l[n - 1]); //put everything to 0, how many flips
        res = std::min(res, r[0]); //put everything to 1, how many flips
        return res;
    }
};