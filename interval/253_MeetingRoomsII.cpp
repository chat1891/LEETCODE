#include <vector>
#include <queue>

/*
Logic:
    - save end time of each room in min heap
    - if top of heap overlap with current time, create a new room
    - if top of the heap has no overlapping, update to new end time

Time: O(n Log n)
    - sorting is n log n
    - worst case if all the meetings will collide with each other,
    then it is O(n log n)

Space: O(n)
    - min heap contains n element in worst case
*/

class Solution
{
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals)
    {
        int n = intervals.size();
        if (n == 0) return 0;

        //pq track end time of each meeting room
        std::priority_queue<int, std::vector<int>, std::greater<int>> rooms;
        sort(intervals.begin(), intervals.end());
        rooms.push(intervals[0][1]);

        for (int i = 1; i < n; i++)
        {
            std::vector<int>& cur = intervals[i];
            if (cur[0] >= rooms.top())
            {
                //no overlap, update to new end time
                rooms.pop();
                rooms.push(cur[1]);
            }
            else
            {
                //overlap, add a new room
                rooms.push(cur[1]);
            }

        }
        return rooms.size();
    }
};