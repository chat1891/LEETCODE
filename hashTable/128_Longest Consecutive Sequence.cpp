#include <string>
using namespace std;
#include <algorithm> 
#include <queue>
#include <set>

//using priority queue
class Solution_priority_queue
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums)
        {
            pq.push(num);
        }

        int cumulative = 0;
        int count = 1;

        while (!pq.empty())
        {
            int cur = pq.top();
            pq.pop();
            if (cur == pq.top() - 1)
            {
                //no need to pop here, because it is while loop
                //poped at beginning
                //cur++;
                //pq.pop();
                count++;
            }
            else if (cur == pq.top())
            {

            }
            else
            {
                count = 1;
            }
            cumulative = max(cumulative, count);
        }

        return cumulative;
    }
};

class Solution_slow
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        set<int> hashSet;
        for (auto num : nums)
        {
            hashSet.insert(num);
        }

        int consecutive = 0;

        for (auto num : nums)
        {
            //check if 1 less than element val present in map then continue 
            //(because we have to find the lowest value from where sequence start)
            if (hashSet.find(num - 1) == hashSet.end())
            {
                //if we don't find (element-1 val in map) then check till (element+1) val present in map and calculate its length and store max length in ans
                int count = 1;
                int cur = num;
                while (hashSet.find(cur + 1) != hashSet.end())
                {
                    count++;
                    cur++;
                }

                consecutive = max(count, consecutive);
            }
        }

        return consecutive;

    }
};

//can also use sort to solve
int longestConsecutive(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    sort(nums.begin(), nums.end());
    int max_count = 1, count = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] == nums[i])
            continue;
        if (nums[i + 1] - nums[i] == 1)
        {
            count++;
            max_count = max(max_count, count);
        }

        else
            count = 1;
    }

    return max_count;
}
