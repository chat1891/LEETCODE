#include <vector>
#include <queue>
#include <math.h>
using namespace std;



//binary search and sliding window
//time log(n) +k
//space O(1)
class Solution_slid
{
public:
    int binarySearch(int l, int r, int x, vector<int>& arr)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] > x)
            {
                r = mid - 1;
            }
            else if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        //return r but l
        return r;
    }

    class comparator
    {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };

    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int n = arr.size() - 1;
        vector<int> res;
        int closest = binarySearch(0, n - 1, x, arr);

        //distance,index
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        //pq.push({abs(arr[closest]-x),closest});

        int left = closest;
        int right = closest + 1;
        while (k > 0)
        {
            k--;
            //be careful about right and left bounds
            if (left == -1 || (right <= n && abs(arr[left] - x) > abs(arr[right] - x)))
            {
                res.push_back(arr[right]);
                right++;
                continue;
            }

            if (right == n + 1 || abs(arr[left] - x) <= abs(arr[right] - x))
            {
                res.push_back(arr[left]);
                left--;
            }

        }

        sort(res.begin(), res.end());
        return res;
    }
};


//modified binary search
//https://leetcode.com/problems/find-k-closest-elements/discuss/1310981/Simple-Solutions-w-Explanation-or-All-Possible-Approaches-Explained!
class Solution_binary
{
public:
    int binarySearch(int l, int r, int x, int k, vector<int>& arr)
    {
        //arr[mid] and arr[mid + k]
        //can only keep one or the other, othewise too much elements

        //[left,right)
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            //the x is even smaller than mid, include left, move right
            if (x < arr[mid])
            {
                r = mid;
            }
            else if (x > arr[mid + k])
            {
                //x is even bigger than right, keep right, move left
                l = mid + 1;
            }
            else if (abs(x - arr[mid]) <= abs(x - arr[mid + k]))
            {
                //left is closer to x, move right
                //need equal condition
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int n = arr.size();
        vector<int> res;
        int left = binarySearch(0, n - k, x, k, arr);

        while (k > 0)
        {
            k--;
            res.push_back(arr[left]);
            left++;
        }

        sort(res.begin(), res.end());
        return res;
    }
};