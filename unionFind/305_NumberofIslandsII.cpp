#include <vector>
/*
- for each position added 
- check its 4 directions
- if any of its neighbors have different parent
- unify this position and this neighbor, because they are connected, should be one island

Time complexity : O(m×n+L) where L is the number of operations, 
m is the number of rows and n is the number of columns. 
it takes O(m×n) to initialize UnionFind, and O(L)O(L) to process positions. 
Note that Union operation takes essentially constant time when UnionFind is implemented with both path compression and union by rank.

Space complexity :O(m×n) as required by UnionFind data structure.
*/
class Solution
{
public:
    //can be optimized by using union find by rank
    class unionFind
    {
    public:
        std::vector<int> parent;
        unionFind(int sz)
        {
            parent = std::vector<int>(sz);
            for (int i = 0; i < sz; i++)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unify(int x, int y)
        {
            parent[find(x)] = parent[y];
        }
    };

    std::vector<std::vector<int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
    int m;
    int n;
    std::vector<std::vector<bool>> isIsland;

    bool isValid(int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return isIsland[i][j];
    }

    int serializeIndex(int& x, int& y)
    {
        return n * x + y;
    }

    std::vector<int> numIslands2(int m, int n, std::vector<std::vector<int>>& positions)
    {
        this->m = m;
        this->n = n;
        unionFind uf = unionFind(m * n);
        std::vector<int> res;
        isIsland = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));

        int count = 0;
        for (auto& pos : positions)
        {
            int& x = pos[0];
            int& y = pos[1];
            if (isIsland[x][y])
            {
                //if already visited
                res.push_back(count);
                continue;
            }
            
            isIsland[x][y] = true;
            count++;
            //every time add a new position (new island)
            //check its 4 directions
            //if any of its neighbors have different parent
            //unify this position and this neighbor
            //because they are connected, should be one island
            for (auto& dir : directions)
            {
                int newx = x + dir[0];
                int newy = y + dir[1];

                if (isValid(newx, newy))
                {
                    int id1 = serializeIndex(x, y);
                    int id2 = serializeIndex(newx, newy);
                    int parent1 = uf.find(id1);
                    int parent2 = uf.find(id2);

                    if (parent1 != parent2)
                    {
                        uf.unify(id1, id2);
                        count--;
                    }
                }
            }

            res.push_back(count);
        }

        return res;
    }
};