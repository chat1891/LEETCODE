#include <vector>
#include <stack>

//use stack
//dfs

//time: O(N+E), N is num of rooms, E is total num of keys
//space: O(n)

class Solution
{
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
    {
        int n = rooms.size();
        std::stack<int> stk;
        stk.push(0);
        std::vector<bool> visited(n, false);
        visited[0] = true; //*init 0 to be visited
        int count = 1;

        while (!stk.empty())
        {
            std::vector<int>& neighbors = rooms[stk.top()];
            stk.pop();
            for (const int& nei : neighbors)
            {
                if (!visited[nei])
                {
                    count++;
                    visited[nei] = true;
                    stk.push(nei);
                }
            }
        }

        return count == n;
    }
};