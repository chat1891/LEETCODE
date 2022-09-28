#include <vector>
using namespace std;

//dp
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            //x/2 is x>>1
            //x%2 is x &1 -> because odd number last digit is definitely 1
            //even number last digit is definitely 0
            ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};


class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            int cur = i;
            int count = 0;
            while (cur != 0)
            {
                cur = cur & (cur - 1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        //*needs to start with 1 not 0
        for (int i = 1; i <= n; i++)
        {
            //put the fist 1 from right to be 0
            //to see if we already calculated it before
            //then add 1 that got deleted before by i&(i-1)
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};