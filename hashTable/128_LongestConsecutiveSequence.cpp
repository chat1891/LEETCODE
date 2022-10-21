#include <string>
#include <algorithm> 
#include <queue>
#include <set>
#include <unordered_map>



/// <summary>
/// ====================================================================
/// approach 1: using priority queue
/// </summary>
class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (auto num : nums)
        {
            pq.push(num);
        }

        int cumulative = 0;
        int count = 1;

        while (!pq.empty())
        {
            int cur = pq.top();
            pq.pop();
            if (cur == pq.top() - 1)
            {
                //no need to pop here, because it is while loop
                //poped at beginning
                //cur++;
                //pq.pop();
                count++;
            }
            else if (cur == pq.top())
            {

            }
            else
            {
                count = 1;
            }
            cumulative = std::max(cumulative, count);
        }

        return cumulative;
    }
};


/// <summary>
/// ========================================================================================
/// approach 2: use sort
/// </summary>
class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::set<int> hashSet;
        for (auto num : nums)
        {
            hashSet.insert(num);
        }

        int consecutive = 0;

        for (auto num : nums)
        {
            //check if 1 less than element val present in map then continue 
            //(because we have to find the lowest value from where sequence start)
            if (hashSet.find(num - 1) == hashSet.end())
            {
                //if we don't find (element-1 val in map) then check till (element+1) val present in map and calculate its length and store max length in ans
                int count = 1;
                int cur = num;
                while (hashSet.find(cur + 1) != hashSet.end())
                {
                    count++;
                    cur++;
                }

                consecutive = std::max(count, consecutive);
            }
        }

        return consecutive;

    }
};

//can also use sort to solve
int longestConsecutive(std::vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;
    sort(nums.begin(), nums.end());
    int max_count = 1, count = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] == nums[i])
            continue;
        if (nums[i + 1] - nums[i] == 1)
        {
            count++;
            max_count = std::max(max_count, count);
        }

        else
            count = 1;
    }

    return max_count;
}


//============================================================================================
/// <summary>
/// approach 3: use union find
/// </summary>
/*
intuitive:
- for each number, if there is num-1, unify num and num -1
- if there is num+1, unify num and num +1
- example:
 [100,4,200,1,3,2]
 [100]
 [4]
 [200]
 [1]
 [3], 3+1 =4 which is visited, unify [3,4]
 [2], 2-1 =1 which is visited, unify [2,1]
      2+1 =3 which is visited, unify [2,3] -> [1,2,3,4]
*/


class Solution
{
public:
    // use size optimized union find to directly get size
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

    int longestConsecutive(std::vector<int>& nums)
    {
        int n = nums.size();
        unionFind uf = unionFind(n);
        std::unordered_map<int, int> visited; //number, index,
        //*have to store index, because it is possible number is negative

        if (n < 2) return n;

        for (int i = 0; i < n; i++)
        {
            //*avoid duplicated number with different index
            if (visited.find(nums[i]) != visited.end())
                continue;

            visited[nums[i]] = i;
            if (visited.find(nums[i] - 1) != visited.end())
            {
                uf.unify(i, visited[nums[i] - 1]);
            }

            if (visited.find(nums[i] + 1) != visited.end())
            {
                uf.unify(i, visited[nums[i] + 1]);
            }
        }

        return uf.getMaxCount();
    }
};