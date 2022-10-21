#include <vector>

class Solution
{
public:
    class unionFind
    {
    private:
        std::vector<int> parent;
    public:
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


    int findCircleNum(std::vector<std::vector<int>>& isConnected)
    {
        int n = isConnected.size();
        unionFind uf = unionFind(n);
        int res = n;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || visited[i][j]) continue;
                visited[i][j] = true;
                visited[j][i] = true;

                if (isConnected[i][j])
                {
                    if (uf.find(i) != uf.find(j))
                    {
                        uf.unify(i, j);
                        res--;
                    }
                }
            }
        }

        return res;
    }
};