#include <vector>

/*
intuition:
- get min and max bloom day from bloomDay list to be left and right bound
- calculate middle bloom day
- chack if can make enough bouquets within this middle bloom day
- if cannot, it means we need more days, so left move to= mid +1;
- if can, it means we can use less days, so right move to mid;

time complexity:
O(n log(a)), a is max in bloomDay list

space complexity:
O(1)
*/



class Solution
{
public:
    bool canMakeBouquets(std::vector<int>& bloomDay, int m, int k, int curDay)
    {
        //check if can make m bouquets within curDays
        int numBouquet = 0;
        int numFlower = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= curDay)
            {
                numFlower++;

                if (numFlower == k)
                {
                    //make one bouquet
                    numBouquet++;
                    numFlower = 0; //finish one bouquet, reset flower
                }
            }
            else
            {
                //cannot get adjacent flowers for bouquet
                //reset number of flowers
                numFlower = 0;
            }

            if (numBouquet >= m) return true;
        }
        return numBouquet >= m;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        //not enough flower for bouquets
        if (n < m * k) return -1;

        int l = 1;
        int r = 1e9;
        //int r = *std::max_element(bloomDay.begin(),bloomDay.end());

        while (l < r)
        {
            //calculate mid day to see if can make m bouquets within mid days.
            int mid = l + (r - l) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid))
            {
                r = mid;
            }
            else
            {
                //cannot make m bouquets
                //need more days
                l = mid + 1;
            }
        }

        return l;
    }
};