#include<vector>
#include <unordered_set>
/*
intuition:
- count number of unique elements bigger than 0
- Same elements, are always same -> Deduplicates
- Different elements, are always different until 0
*/

class Solution
{
public:
    int minimumOperations(std::vector<int>& nums)
    {
        std::unordered_set<int> mp(nums.begin(), nums.end());

        //size if the set - count of 0
        return mp.size() - mp.count(0);

    }
};