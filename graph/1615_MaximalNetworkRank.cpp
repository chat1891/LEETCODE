#include<vector>

/*
- find how many edges go from each node,
- for all possible combination of cities, just sum all the edges together
- subtract duplicated pair that counted twice for same road
*/

class Solution
{
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads)
    {
        //if city 1 and city 2 are connected, set to1
        //[city1][city2] = 1
        //[city2][city1] = 1
        std::vector<std::vector<int>> roadsGraph(n, std::vector<int>(n, 0));
        std::vector<int> roadCount(n); //number of road connected to the city

        for (auto& road : roads)
        {
            roadsGraph[road[0]][road[1]] = 1;
            roadsGraph[road[1]][road[0]] = 1;

            roadCount[road[0]]++;
            roadCount[road[1]]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = roadCount[i] + roadCount[j];

                //if i and j are connected, minus 1 to only count 1 pair
                if (roadsGraph[i][j] == 1)
                {
                    count--;
                }

                res = std::max(res, count);
            }
        }

        return res;
    }
};