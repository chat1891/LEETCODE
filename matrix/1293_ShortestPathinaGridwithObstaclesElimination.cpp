#include<vector>
#include <queue>

/*

1. Since it talks about the shortest paths, we immediately think about BFS here.
    2. We use the visited array in a different way to keep storing the number of obstacles
        that we can still remove after walking through that cell. (Basically BEST remaining K after reaching that cell)
    3. Simply traverse the BFS by storing the X, Y, currentLength and currentK remaining in the queue.
    4. If you reach the destination index, return the currentLength
    5. If you try to access an invalid cell,
        or you hit an obstacle but have no K to spend,
        or this index X and Y have already been accessed and with a better remaining K than yours, WE SKIP/continue.
    6. Push the adjacent indexes into the queue.

    Time : O(mn)
    Space: O(mn)
*/
class Solution
{
public:
    int shortestPath(std::vector<std::vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        //x,y, steps, k left
        std::queue<std::vector<int>> que;
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, -1));
        que.push({ 0,0,0,k });
        while (!que.empty())
        {
            auto cur = que.front();
            que.pop();
            int& x = cur[0]; int& y = cur[1];
            int& step = cur[2]; int& remain = cur[3];
            //out of boundary
            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            //reach the end, return result
            if (x == m - 1 && y == n - 1) return step;

            if (grid[x][y] == 1)
            {
                // If we encounter an obstacle and we can remove it
                if (remain > 0)
                {
                    remain--;
                }
                else
                {
                    continue;
                }
            }

            // The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
            // Then we don't need to continue on our current path
            if (visited[x][y] != -1 && visited[x][y] >= remain)
                continue;

            visited[x][y] = remain;
            step++;
            que.push({ x + 1,y,step,remain });
            que.push({ x,y + 1,step,remain });
            que.push({ x - 1,y,step,remain });
            que.push({ x,y - 1,step,remain });
        }

        return -1;
    }
};