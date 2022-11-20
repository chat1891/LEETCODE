#include <vector>
/*
- group stone by same col or same row
- count how many unify it has, or number of stone - num of groups
*/


class unionFind
{
public:
    std::vector<int> parent;
    std::vector<int> sizes;
    int groups;

    unionFind(int sz)
        :parent(std::vector<int>(sz)),
        sizes(std::vector<int>(sz, 1)),
        groups(0)
    {
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

    int unify(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);

        if (rootx == rooty)
        {
            return 0;
        }

        if (sizes[rootx] <= sizes[rooty])
        {
            parent[rootx] = parent[rooty];
            sizes[rooty] += sizes[rootx];
        }
        else
        {
            parent[rooty] = parent[rootx];
            sizes[rootx] += sizes[rooty];
        }
        groups++;
        return 1;
    }
};

class Solution
{
public:
    int shareSameRowOrColumn(std::vector<int>& a, std::vector<int>& b)
    {
        return a[0] == b[0] || a[1] == b[1];
    }


    int removeStones(std::vector<std::vector<int>>& stones)
    {
        unionFind* uf = new unionFind(stones.size());
        int n = stones.size();
        int count = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (shareSameRowOrColumn(stones[i], stones[j]))
                {
                    count -= uf->unify(i, j);
                }
            }
        }
        return uf->groups;
        //return n-count;
    }
};