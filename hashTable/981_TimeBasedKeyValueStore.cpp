#include <unordered_map>
#include <map>
#include <string>

class TimeMap
{
public:
    std::unordered_map<std::string, std::map<int, std::string>> mp;

    TimeMap()
    {

    }

    void set(std::string key, std::string value, int timestamp)
    {
        mp[key].insert({ timestamp,value });
    }

    //use upper bound
    std::string get(std::string key, int timestamp)
    {

        auto it = mp[key].upper_bound(timestamp);
        //iterator at beginning means the first item is bigger than timestamp
        //means no smaller or equal time, no match, return empty string
        if (it == mp[key].begin())
        {
            auto fbegin = mp[key];

            return "";
        }
        //means it points to the first one bigger than timestamp
        //take the previous one
        it--;
        return it->second;
    }

    //use lower bound
    std::string get2(std::string key, int timestamp)
    {
        if (!mp.count(key)) return "";

        auto found = mp[key].lower_bound(timestamp);
        //first one is equal or bigger than timestamp
        //check if it is equal, if not equal means it is bigger, no match
        if (found == mp[key].begin() && found->first != timestamp)
        {
            return "";
        }
        //found == mapping[key].end() : if didn't find equal or bigger, means just smaller than time stamp
        //found->first > timestamp: found the one bigger take the previous one
        //if found the one equal, no need to take previous one
        if (found == mp[key].end() || found->first > timestamp)
        {
            found--;
        }
        return found->second;

    }

};
