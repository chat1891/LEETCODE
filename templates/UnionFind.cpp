#include <vector>

#pragma region regular union find
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
#pragma endregion

//===========================================================
#pragma region union find optimized based on size
class unionFind
{
private:
    std::vector<int> parent;
    int maxCount = 1;
public:
    std::vector<int> unionSize;
    unionFind(const int& n)
    {
        parent = std::vector<int>(n);
        unionSize = std::vector<int>(n, 1);

        for (int i = 0; i < n; i++)
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

        if (unionSize[rootx] <= unionSize[rooty])
        {
            parent[rootx] = parent[rooty];
            unionSize[rooty] += unionSize[rootx];
            maxCount = std::max(maxCount, unionSize[rooty]);
        }
        else
        {
            parent[rooty] = parent[rootx];
            unionSize[rootx] += unionSize[rooty];
            maxCount = std::max(maxCount, unionSize[rootx]);
        }
    }

    int getMaxCount()
    {
        return maxCount;
    }

};
#pragma endregion

//===========================================================
#pragma region union find optimized by rank
//rank can be considered like height
class unionFind
{
private:
    std::vector<int> parent;
public:
    std::vector<int> rank;
    unionFind(const int& n)
    {
        parent = std::vector<int>(n);
        rank = std::vector<int>(n);

        for (int i = 0; i < n; i++)
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

        if (rank[rootx] < rank[rooty])
        {
            //rank will not increase, if attach smaller height to bigger height
            parent[rootx] = rooty;
        }
        else if (rank[rootx] > rank[rooty])
        {
            parent[rooty] =rootx;
        }
        else
        {
            parent[rootx] = rooty;
            //only when rank are equal, the rank will increase
            rank[rooty]++;
        }
    }

};
#pragma endregion
