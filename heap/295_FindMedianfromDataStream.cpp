#include<queue>

//use max heap and min heap
//youtube.com/watch?v=itmhHWaHupI
/*
[1, 2, 3, 4]
small heap (max heap) first half : [1,2] >= large Heap (min heap) second half: [3,4]



Time complexity: O(5 logn)+O(1) = O(logn).

At worst, there are three heap insertions and two heap deletions from the top.
Each of these takes about O(logn) time.
Finding the median takes constant O(1) time since the tops of heaps are directly accessible.

Space: O(n)
*/
class MedianFinder
{
public:
    std::priority_queue<int> maxHeap;                              // max heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;   // min heap
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        /*
       max heap: [2]
       min heap:[3]
       add 7
       */
       //make sure every number in maxHeap<= min heap
        maxHeap.push(num); //[2,7]
        minHeap.push(maxHeap.top()); //[3,7]
        maxHeap.pop(); //[2]

        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top()); //[2,3]
            minHeap.pop(); //[7]
        }
    }

    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
        {
            //odd count
            //return middle
            return maxHeap.top();
        }
        else
        {
            //return half of sum of two center elements
            return ((double)maxHeap.top() + minHeap.top()) / 2;
        }
    }
};

//===================
//approach 2: simple sort
//time limit exceeds

/*
Time complexity: O(n log n) + O(1) = O(n logn).
Space O(n)
*/
class MedianFinder
{
public:
    std::vector<double> store;
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        store.push_back(num);
    }

    double findMedian()
    {
        sort(store.begin(), store.end());
        int n = store.size();
        if (n & 1)
        {
            //odd count
            return store[n / 2];
        }
        else
        {

            return (store[n / 2 - 1] + store[n / 2]) / 2;
        }
    }
};