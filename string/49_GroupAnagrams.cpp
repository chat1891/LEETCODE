#include <vector>
#include <unordered_map>
#include <string>

/*
Intuition
- create a map to save sorted string as key and it is index in result list
- for each word in strs, sort it to check if the key is in map
- if it is in map, get index and add to res
- if not, create a new list add to res

time O(n* m logm)
    n is length of strs
    m is average length of string
space O(n m)
*/
class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>&strs)
    {
        std::unordered_map<std::string, int> mp; //string, index
        std::vector<std::vector<std::string>> res;
        int idx = 0;

        for (int i = 0; i < strs.size(); i++)
        {
            std::string cur = strs[i];
            sort(cur.begin(), cur.end());
            if (mp.count(cur) == 0)
            {
                mp[cur] = idx;
                std::vector<std::string> curRes = { strs[i] };
                res.push_back(curRes);
                idx++;
            }
            else
            {
                res[mp[cur]].push_back(strs[i]);
            }
        }

        return res;

    }
};