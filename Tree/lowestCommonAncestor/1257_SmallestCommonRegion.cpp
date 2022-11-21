#include <unordered_set>
#include <unordered_map>

//lowest common ancestor
class Solution
{
public:
    std::unordered_set<std::string> findPath(std::unordered_map<std::string, std::string>& mp, std::string str)
    {
        std::unordered_set<std::string> paths;
        while (str != "")
        {
            paths.insert(str);
            str = mp[str];
        }
        return paths;
    }

    std::string findSmallestRegion(std::vector<std::vector<std::string>>& regions, std::string region1, std::string region2)
    {
        std::unordered_map<std::string, std::string>mp;
        //init to ""
        mp[regions[0][0]] = "";
        for (int i = 0; i < regions.size(); i++)
        {
            std::string parent = regions[i][0];
            for (int j = 1; j < regions[i].size(); j++)
            {
                mp[regions[i][j]] = parent;
            }
        }

        std::unordered_set<std::string> path1 = findPath(mp, region1);

        while (region2 != "")
        {
            if (path1.count(region2) == 0)
            {
                region2 = mp[region2];
            }
            else
            {
                return region2;
            }
        }


        return region2;
    }
};