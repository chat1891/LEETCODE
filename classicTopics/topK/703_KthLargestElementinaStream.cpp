#include <queue>

/*
follow up:
- query heavy, have lots of different k in query:
    - if it is not stream, give all the data at once, just sort it and take numbers from [n-k] to n
    so that every time is O(k)
*/


/// <summary>
/// use min heap
/// 
/// Time: O(N * log(N)+M*log(k))
/// Given N as the length of nums and M as the number of calls to add()
/// 1. the constructor needs to turn nums into a heap of size k which is O(N log k).
/// 2. Then, we need to remove from the heap until there are only k elements in it, which means removing N - k elements 
/// k can be 1, so there are N operations, each cost log N, 
/// so: O(N log(k) +N*log(N))=O(N*log(N))
/// 
/// 3. every call to add() involves adding an element to heap and potentially removing an element from heap. 
/// Since our heap is of size k, every call to add() at worst costs 2*log (K) =log (K) 
/// That means M calls to add() costs M*log (K)
/// 
/// </summary>
class KthLargest
{
public:
    //min heap
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int k = 0;
    KthLargest(int k, std::vector<int>& nums)
    {
        this->k = k;
        for (auto& num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */