#include <unordered_map>
/*
* 
- build up disjoint sets, unify different islands in original matrix
- also add size array in union find to quickly get its size
- iterate each water cells, sum up sizes of its neighbor island and take maximum

 Time complexity: O(n * m)
 Space complexity: O(n * m)
*/
class unionFind
{
private:
    int maxSize = 1; //min size is 1
public:
    std::vector<int> sizes;
    std::vector<int> parent;

    unionFind(int sz)
    {
        sizes = std::vector<int>(sz, 1);
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
        int rootx = find(x);
        int rooty = find(y);

        if (rootx == rooty) return;
        if (sizes[rootx] > sizes[rooty])
        {
            parent[rooty] = rootx;
            sizes[rootx] += sizes[rooty];
            maxSize = std::max(sizes[rootx], maxSize);
        }
        else
        {
            parent[rootx] = rooty;
            sizes[rooty] += sizes[rootx];
            maxSize = std::max(sizes[rooty], maxSize);
        }
    }

    int getMaxSize()
    {
        return maxSize;
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> visited;
    std::vector<std::vector<int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
    int n, m;

    int serialization(const int& x, const int& y)
    {
        return x * n + y;
    }

    bool isValid(const int& x, const int& y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }

    void unifyDfs(std::vector<std::vector<int>>& grid, int x, int y, unionFind& uf)
    {
        if (!isValid(x, y)) return;
        if (visited[x][y]) return;

        visited[x][y] = true;
        if (grid[x][y] == 1)
        {
            int id1 = serialization(x, y);
            for (auto& dir : directions)
            {
                int newx = x + dir[0];
                int newy = y + dir[1];
                int id2 = serialization(newx, newy);
                if (isValid(newx, newy) && grid[newx][newy] == 1)
                {
                    if (uf.find(id1) != uf.find(id2))
                        uf.unify(id1, id2);

                    unifyDfs(grid, newx, newy, uf);
                }

            }
        }

    }
    int largestIsland(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        
        unionFind uf = unionFind(m * n);
        visited = std::vector<std::vector<int>>(m, std::vector<int>(n, false));
        //build up unions, unify different islands in original matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    unifyDfs(grid, i, j, uf);
                }
            }
        }

        int res = uf.getMaxSize();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    //for each water cell, calculate sum of its neighbor islands
                    //use map to avoid duplication
                    std::unordered_map<int, int> mp; //neighbor id, size
                    for (auto& dir : directions)
                    {
                        int newx = i + dir[0];
                        int newy = j + dir[1];
                        int id2 = serialization(newx, newy);
                        if (isValid(newx, newy) && grid[newx][newy] == 1)
                        {
                            //*need to get parent id for getting correct size
                            int parent2 = uf.find(id2);
                            if (mp.count(parent2) == 0)
                            {
                                mp[parent2] = uf.sizes[parent2];
                            }
                        }
                    }
                    int sumNeighbor = 0;
                    for (auto& item : mp) sumNeighbor += item.second;
                    res = std::max(res, sumNeighbor + 1);
                }
            }
        }

        return res;
    }
};