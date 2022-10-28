#include <vector>
using namespace std;
#include <unordered_map>
#include <queue>


/*
follow up:
can ask the relationship between n and k, if n=200, k=2
we can optimize to find minimum 2 numbers, and rest is the answer
*/


//use bucket sort
//https://www.youtube.com/watch?v=YPTqKIgVk-k
class Solution_bucket
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);//frequency, numbers with same frequency
        vector<int> res;
        unordered_map<int, int> freq;

        //get frequency of each number
        for (const auto& num : nums)
        {
            freq[num]++;
        }

        //put number in frequency slot
        //bucket index is frequency
        for (const auto& item : freq)
        {
            bucket[item.second].push_back(item.first);
        }

        //from end to start, take the numbers with most frequency
        //time O(n)
        for (int i = n; i >= 0; i--)
        {
            if (bucket[i].size() != 0)
            {
                //here the max time is O(n)
                //when all the numbers have same frequency
                //they will all be in same slot
                //the total time will be O(n)+O(n), 
                //because this O(n) will only be looped once
                for (int j = 0; j < bucket[i].size() && k>0; j++)
                {
                    res.push_back(bucket[i][j]);
                    k--;
                }
            }
        }

        return res;

    }
};


//===============================================================================
/// <summary>
/// APPROACH 2 minHeap
/// time: O(n logk), k<n
/// when n=k -> O(n)
/// space O(n+k)
/// </summary>
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> res;
        unordered_map<int, int> freq;//number,freq

        //get frequency of each number
        for (const auto& num : nums)
        {
            freq[num]++;
        }

        for (const auto& item : freq)
        {
            minHeap.push({ item.second,item.first });
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};