#include <unordered_map>
#include <unordered_set>

/// <summary>
/// find O(n)
/// add O(1)
/// </summary>
class TwoSum
{
public:
    std::unordered_map<long, long> mp;//number, count
    TwoSum()
    {

    }

    void add(int number)
    {
        mp[number]++;
    }

    bool find(int value)
    {
        for (auto& num : mp)
        {
            long diff = value - num.first;
            if (mp.count(diff) != 0)
            {
                if (diff != num.first)
                    return true;
                else
                {
                    //diff might be same as the number
                    //if diff same as the number, need to have frequency >1
                    if (mp[diff] > 1)
                        return true;
                }
            }

        }
        return false;
    }
};

//trade off, if find operation is way bigger than add
//this approach: add: O(n^2), find O(1)

class TwoSum
{
public:
    std::unordered_set<int> numMap;
    std::unordered_set<int> sumMap;
    TwoSum()
    {

    }

    //for each number add, calculate its sum and save in sumMap
    void add(int number)
    {
        for (auto& n : numMap)
        {
            sumMap.insert(n + number);
        }
        numMap.insert(number);
    }

    bool find(int value)
    {
        return sumMap.count(value) > 0;
    }
};
