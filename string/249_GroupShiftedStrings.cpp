#include <string>
#include <vector>
#include<unordered_map>

class Solution
{
public:
    char shifLetter(char& letter, int& shift)
    {
        //add 26 in case of negative values
        //because it is circular
        return (letter - shift + 26) % 26 + 'a';
    }

    std::string shifString(std::string& str)
    {
        int shift = str[0];
        std::string hashKey;

        for (auto& c : str)
        {
            hashKey += shifLetter(c, shift);
        }

        return hashKey;
    }

    std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings)
    {
        //shift first letter to a, 
        //and shift every letter after based on same value shifted from first letter
        std::unordered_map<std::string, std::vector<std::string>> mp; //shifted to a, list of original string

        for (auto& str : strings)
        {
            std::string hash = shifString(str);
            mp[hash].push_back(str);
        }

        std::vector<std::vector<std::string>> res;
        for (auto& g : mp)
        {
            res.push_back(g.second);
        }

        return res;
    }
};