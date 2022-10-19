#include <vector>
#include <stack>

//0,[3,2,4,5],1,9,8
//     ^ 
//for 2 as min, left have 2 positions, right has 3 positions
//total is 2*3 = 6



class Solution
{
public:
    int sumSubarrayMins(std::vector<int>& arr)
    {
        int n = arr.size();
        std::vector<int> prevSmaller(n, -1);
        std::stack<int> stk;
        long long mod = 1e9 + 7;
        long long res = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
            {
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();
        std::vector<int> nextSmaller(n, n);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && arr[stk.top()] > arr[i])
            {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            long long l = prevSmaller[i];
            long long r = nextSmaller[i];
            long long num = ((arr[i] * (i - l) * (r - i)));
            res = (res + num) % mod;
        }

        return res;

    }
};