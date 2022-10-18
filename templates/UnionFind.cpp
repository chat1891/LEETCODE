#include <vector>

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
            //path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unify(int x, int y)
    {
        parent[find(x)] = parent[y];
    }
};
