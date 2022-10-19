#include <vector>
#include <string>
#include <unordered_map>
#include<queue>

/// <summary>
/// use max heap
/// 
/// Time Complexity:O(N+klogN)
/// We count the frequency of each word in O(N) time 
/// and then heapify the list of unique words in O(N) time. 
/// Each time we pop the top from the heap, it logN time as the size of the heap is O(N)
/// 
/// space complexity O(N)
/// </summary>
class Solution
{
public:
    class myCompare
    {
    public:
        bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
        {
            //use max heap
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        }
    };

    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
    {
        std::unordered_map<std::string, int> mp;
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, myCompare> pq;

        for (auto& word : words)
        {
            mp[word]++;
        }

        for (auto& item : mp)
        {
            pq.push({ item.first,item.second });
        }

        std::vector<std::string> res;
        while (k)
        {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return res;
    }
};

/// <summary>
/// use min heap to keep priority size to k
/// 
/// Time Complexity:O(Nlogk), where N is the length of words. 
/// We count the frequency of each word in O(N) time, then we add N words to the heap, each in O(logk) time. 
/// Finally, we pop from the heap up to k times or just sort all elements in the heap as the returned result, which takes O(klogk). 
/// As k<=N, O(N)+O(Nlogk)+O(klogk)=O(Nlogk)
/// 
///Space Complexity : O(N), O(N) space is used to store our counter cnt while O(k) space is for the heap.
/// </summary>
class Solution
{
public:
    class myComparator
    {
    public:
        bool operator()(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
        {
            if (a.first == b.first)
            {
                //return lexicographical_compare(a.second.begin(), a.second.end(), b.second.begin(), b.second.end());
                return a.second < b.second;
            }
            // min heap
            return a.first > b.first;
        }
    };

    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
    {
        std::unordered_map<std::string, int> freq;
        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, myComparator> pq;

        for (auto word : words) freq[word]++;

        for (const auto& word : freq)
        {
            pq.push({ word.second, word.first });
            //to keep pq size to be k, pop minimum one, so use min heap, to pop smallest one at top
            if (pq.size() > k)
            {
                pq.pop();

            }
        }

        std::vector<std::string> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};


//Approach 3: Bucket Sorting + Trie