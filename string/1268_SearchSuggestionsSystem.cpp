#include <string>
#include <vector>
#include <algorithm>

/*
- sort the list
- use two pointers, left from beginning and right from end
- check if left matches,
    - if yes, check if right matches
        -if right matches, means everything between left and right are matching
        - if right not match, right --
    - if left not match, left++, till find a match
*/

class Solution
{
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord)
    {
        sort(products.begin(), products.end());
        int n = searchWord.size();
        int left = 0;
        int right = products.size() - 1;
        int i = 0;
        std::vector<std::vector<std::string>> res;

        while (i < n)
        {
            char cur = searchWord[i];
            std::vector<std::string> curRes;
            //*careful use while loop here, and condition to check product size
            while (left <= right && (i >= products[left].size() || products[left][i] != cur))
            {
                left++;
            }

            while (left <= right && (i >= products[right].size() || products[right][i] != cur))
            {
                right--;
            }

            //left and right both find a match
            int idx = left;
            int count = 0;
            while (idx <= right && count < 3)
            {
                curRes.push_back(products[idx]);
                count++;
                idx++;
            }

            res.push_back(curRes);
            i++;

        }

        return res;
    }
};


//can also use trie to solve