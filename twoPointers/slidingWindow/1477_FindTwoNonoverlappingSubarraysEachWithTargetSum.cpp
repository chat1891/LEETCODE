#include <vector>

class Solution
{
public:
    int minSumOfLengths(std::vector<int>& arr, int target)
    {
        int n = arr.size();
        //minLens[i] is the min length of a valid subarray before i
        std::vector<int> min_lens(n, INT_MAX / 2);

        int l = 0;
        int r = 0;
        int sum = 0;
        int res = INT_MAX;
        int minLenSofar = INT_MAX / 2;

        while (r < n)
        {
            sum += arr[r];
            while (sum > target)
            {
                sum -= arr[l];
                l++;
            }

            if (sum == target)
            {
                int curLen = r - l + 1;
                minLenSofar = std::min(minLenSofar, curLen);

                if (l > 0 && min_lens[l - 1] != INT_MAX / 2)
                {
                    //update result when find two sub arrays
                    //cur subarray length + previous min sub array length
                    res = std::min(curLen + min_lens[l - 1], res);
                }
            }
            //*outside of if condition, we want to continuous update it with min length we get so far
            min_lens[r] = minLenSofar;
            r++;
        }

        //** bigger than INT_MAX/2
        return res >= INT_MAX / 2 ? -1 : res;
    }
};

//========================================================
//prefixsum
//only if all the numbers are positive
class Solution
{
public:
    int minSumOfLengths(std::vector<int>& arr, int target)
    {

        int kmax = INT_MAX / 2;
        int n = arr.size();
        std::vector<int> minLens(n + 1, kmax);
        //use n+1, because prefixSum of arr[0] cannot use prefixSum[0] - prefixSum[0]
        std::vector<int> prefixSum(n + 1);
        prefixSum[1] = arr[0];
        for (int i = 2; i <= n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }

        int s = 0;
        int minLen = kmax;
        int res = kmax;
        //int curSum=prefixSum[0]
        for (int e = 0; e <= n; e++)
        {
            while (prefixSum[e] - prefixSum[s] > target)
            {
                s++;
            }

            if (prefixSum[e] - prefixSum[s] == target)
            {
                int curLen = e - s;
                minLen = std::min(minLen, curLen);
                if (s > 0)
                {
                    res = std::min(res, curLen + minLens[s]);
                }
            }
            minLens[e] = minLen;
        }

        return res >= kmax ? -1 : res;

    }
};