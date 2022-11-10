#include <vector>

/*
Time O(n)
Space O(n)

prefix sum
//google doc
*/
class Solution
{
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen)
    {
        std::vector<int> preSum = nums;
        if (firstLen + secondLen > nums.size()) return 0;

        for (int i = 1; i < nums.size(); i++)
        {
            preSum[i] += preSum[i - 1];
        }

        int maxFirst = preSum[firstLen - 1];
        int maxSecond = preSum[secondLen - 1];
        int res = preSum[firstLen + secondLen - 1];

        for (int i = firstLen + secondLen; i < nums.size(); i++)
        {
            //first before second
            maxFirst = std::max(preSum[i - secondLen] - preSum[i - firstLen - secondLen], maxFirst);
            int maxSum1 = maxFirst + (preSum[i] - preSum[i - secondLen]);

            //second before first
            maxSecond = std::max(preSum[i - firstLen] - preSum[i - firstLen - secondLen], maxSecond);
            int maxSum2 = maxSecond + (preSum[i] - preSum[i - firstLen]);

            res = std::max(res,
                std::max(maxSum1, maxSum2));
        }
        return res;

    }
};


/*
Time O(n)
Space O(1)

sliding window
*/