#include <vector>
#include <stack>


//monotonic stack
//sum of subarray max - sum of subarray min
//= sum of subarray (max - min)
//= sum of subarray range
//https://www.youtube.com/watch?v=xba0NzSbuas

/*
1,3,4,5,2,7,8,9,10,11,1
        ^
if 2 is the smallest, how many ways we can set the range
left: 1,[3,[4,[5,[2,7,8,9,10,11,1
so number of ways to add left boundary is i-L =4-0= 4
where L is previous smaller

right: 1,3,4,5,2],7],8],9],10],11],1
so number of ways to add right boundary is R-i = 10-4=6
where R is next smaller

so number of subarray with 2 is the smallest is (i-L) * (R-i)

*/

/*
- it is possible to have multiple same smallest number is one range
3,8,4,4,8,4,5,6,4,3
          ^
we can just set the left most is the smallest
left: 3,[8,[4,[4,[8,[4,4,5,6,4,3
so the left we set to be the strict smaller

right: 3,8,4,4,8,4],5],6],4,3
right to be the smaller or equal, stop at equal as well

*/
class Solution
{
public:
    long long subArrayRanges(std::vector<int>& nums)
    {
        int n = nums.size();
        std::stack<int> stk;

        std::vector<int> nextSmaller(n, n);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[i] <= nums[stk.top()])
            {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        std::vector<int> prevSmaller(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[i] < nums[stk.top()])
            {
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        std::vector<int> nextBigger(n, n);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[i] >= nums[stk.top()])
            {
                nextBigger[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        std::vector<int> prevBigger(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[i] > nums[stk.top()])
            {
                prevBigger[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            //if the number is the biggest
            //left boundary is whatever cannot be bigger than it
            int l = prevBigger[i];
            int r = nextBigger[i];
            res += (long long)nums[i] * (i - l) * (r - i);

            //if the number is the smallest
            int ls = prevSmaller[i];
            int rs = nextSmaller[i];
            res -= (long long)nums[i] * (i - ls) * (rs - i);
        }

        return res;

    }
};

//brute force
//Time: O(n^2)
class Solution_2
{
public:
    long long subArrayRanges(std::vector<int>& nums)
    {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int maxNum = nums[i];
            int minNum = nums[i];
            for (int j = i; j < n; j++)
            {
                maxNum = std::max(maxNum, nums[j]);
                minNum = std::min(minNum, nums[j]);
                res += (maxNum - minNum);
            }
        }

        return res;
    }
};