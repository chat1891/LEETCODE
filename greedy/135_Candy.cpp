#include <vector>
#include <numeric>

//https://www.youtube.com/watch?v=QzPWc0ilEek
class Solution
{
public:
    int candy(std::vector<int>& ratings)
    {
        int n = ratings.size();
        std::vector<int> candies(n, 1);

        //check if current candy satisfy the conditions compare to its left neighbor
        //case 1 if r[i] < r[i+1]
        //candies[i] < candies[i+1]

        //case 2: if r[i] > r[i+1]-> r[i-1] > r[i]
        //candies[i] >= candies[i+1] -> candies[i-1] >= candies[i]
        //this case it doesn't change in this loop
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] = std::max(1, candies[i - 1] + 1);
        }

        //check if current candy satisfy the conditions compare to its right neighbor

        //case 1: for  r[i] < r[i+1]
        //candies[i] < candies[i+1]
        //so nothing changes in this round

        //case 2: if r[i] > r[i+1]
        //candies[i] > candies[i+1] 
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }

        int res = accumulate(candies.begin(), candies.end(), 0);
        return res;
    }
};