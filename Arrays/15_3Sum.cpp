#include <vector>
#include<algorithm>
#include <unordered_set>
#include <set>
//https://www.youtube.com/watch?v=jzZsG8n2R9A

//time: O(N LOG(N)) + N*N = O(n^2)
//      SORT          loop
//space O(1) OR O(n) depends on sorting algorithm

//approach 1: use two pointers
//this approach is easier than hashset for removing duplicates, and doesn't require extra space like hashset

//If an interviewer asks you whether you can achieve O(1) memory complexity, 
//you can use the selection sort instead of a built-in sort in the Two Pointers approach. 
//It will make it a bit slower, though the overall time complexity will be still O(n^2)
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            //do not want to check duplicated ones
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            //solve two sum
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int threeSum = a + nums[left] + nums[right];
                if (threeSum > 0)
                {
                    //sum is too big, move right pointer to get smaller num
                    right--;
                }
                else if (threeSum < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back({ a,nums[left],nums[right] });
                    left++;
                    right--;
                    //[-1,-1,0,0,1,1]
                    //left ++ = 1, which is same as previous

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        //remove duplicates from left
                        //move left to 2
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1])
                    {
                        //remove duplicates from right
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

//========================================================================
//approach 2: hashset
// this is much slower than two pointers, plus need space for hash set
//Time: O(n^2), 
// -two sum is O(n), we call it n times
// -sort is O(N LOG(N))

//space O(n) for hash set

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<std::vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            //remove duplicates
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            //optimization:
            //if a >0, b and c will also >, they cannot sum to 0
            if (nums[i] > 0) break;
            int curTarget = -nums[i];

            //two sum for getting newTarget
            std::unordered_set<int> hashset;
            for (int left = i + 1; left < n; left++)
            {
                int c = curTarget - nums[left];
                if (hashset.count(c) != 0)
                {
                    res.push_back({ -curTarget,nums[left],c });
                    //remove duplicates
                    while (left < n - 1 && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                }
                hashset.insert(nums[left]);
            }

        }
        return res;
    }
};


//=======================================================================
//Approach 3: "No-Sort"
//What if you cannot modify the input array, and you want to avoid copying it due to memory constraints
//We can adapt the hashset approach above to work for an unsorted array


/*
Time O(n^2)
While the asymptotic complexity is the same, this algorithm is noticeably slower than the previous approach.
Lookups in a hashset, though requiring a constant time, are expensive compared to the direct memory access.

Space O(n) for hashSet and hashMap
For the purpose of complexity analysis, we ignore the memory required for the output. 
However, in this approach we also store output in the hashset for deduplication.

in worst case, there could be O(n^2) triplets in the output
like for this example: [-k, -k + 1, ..., -1, 0, 1, ... k - 1, k]
Adding a new number to this sequence will produce n / 3 new triplets.
*/

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        int n = nums.size();
        std::set<std::vector<int>> res;
        //Use another hashset dups to skip duplicates in the outer loop
        std::unordered_set<int> dups;

        for (int i = 0; i < n; i++)
        {
            //remove duplicates
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int curTarget = -nums[i];
            //insert Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) 
            //and a bool denoting whether the insertion took place.
            if (dups.insert(nums[i]).second)
            {
                //two sum for getting newTarget
                std::unordered_set<int> hashset;
                for (int left = i + 1; left < n; left++)
                {
                    int c = curTarget - nums[left];
                    if (hashset.count(c) != 0)
                    {
                        std::vector<int> triplet = { -curTarget,nums[left],c };
                        sort(triplet.begin(), triplet.end());
                        res.insert(triplet);
                        //remove duplicates
                        while (left < n - 1 && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                    }
                    hashset.insert(nums[left]);
                }
            }

        }
        return std::vector<std::vector<int>>(begin(res), end(res));
    }
};