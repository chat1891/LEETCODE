#include <map>

/*
- log time to the timeline
- add one event at start
- remove event at end
- iterate the timeline again to get max number of events

time: O(N^2)
- each event, update two points in timeline O(log n)
- traverse diff in O(N)

Space O(N)
*/

//https://www.youtube.com/watch?v=tReqj-t0rq0

class MyCalendarThree
{
public:
    std::map<int, int> mp; //time, sum
    MyCalendarThree()
    {

    }

    int book(int start, int end)
    {
        mp[start]++; //add one new event
        mp[end]--; //the event ends

        int res = 0;
        int sum = 0;
        for (auto& [time, diff] : mp)
        {
            sum += diff;
            res = std::max(res, sum);
        }

        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */