#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

/// <summary>
/// bfs
/// - add bank words to set and visited set
/// - add start to queue
/// - for each level in queue, check every letter in current word changed to 4 different choices
/// - if find a variation in bank, mark as visited and add to queue
/// - until find end
/// </summary>
class Solution
{
public:
    int minMutation(std::string start, std::string end, std::vector<std::string>& bank)
    {
        int n = bank.size();
        std::unordered_set<std::string> bankSet;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        for (int i = 0; i < n; i++)
        {
            bankSet.insert(bank[i]);
        }

        q.push(start);
        std::vector<char> choices = { 'A','C','G','T' };
        int step = 0;

        while (!q.empty())
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                std::string cur = q.front();
                q.pop();
                if (cur == end)
                {
                    return step;
                }
                //for each letter, change for all 4 possibilities
                for (int c = 0; c < 8; c++)
                {
                    std::string nextStr = cur;

                    for (auto& choice : choices)
                    {

                        nextStr[c] = choice;

                        if (bankSet.count(nextStr) != 0 && visited.count(nextStr) == 0)
                        {
                            //step++;
                            visited.insert(nextStr);
                            q.push(nextStr);
                        }
                    }

                }

            }
            step++;
        }

        return -1;

    }
};