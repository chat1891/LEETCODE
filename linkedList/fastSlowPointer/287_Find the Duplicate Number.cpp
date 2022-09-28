#include <string>
using namespace std;
#include <tuple>
#include <algorithm> 
#include <queue>


//Spcace: O(1)
//time: O(n)
//https://leetcode.com/problems/find-the-duplicate-number/
//solution in leetcode is explained

//can also use hashMap, but space is O(n)
//sort or times -1 both modifies array

//follow up question:
//https://youtu.be/gDxv49BGz0w?t=2319
class Solution_slowFastPointer
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};