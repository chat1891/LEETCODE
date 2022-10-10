#include <vector>
#include <string>
#include <map>
#include <set>

class Solution
{
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs)
    {
        //string content, identifier
        //use set to sort identifier if they have same content
        std::map<std::string, std::set<std::string>> letters;
        std::vector<std::string> digits;

        for (auto& log : logs)
        {
            int i = 1;
            while (log[i] != ' ')
            {
                i++;
            }
            std::string identifier = log.substr(0, ++i);
            if (isdigit(log[i]))
            {
                digits.push_back(log);
            }
            else
            {
                std::string content = log.substr(i);
                letters[content].insert(identifier);
            }
        }

        std::vector<std::string> res;
        for (auto& let : letters)
        {
            for (auto& iden : let.second)
            {
                res.push_back(iden + let.first);
            }
        }

        for (auto& dig : digits)
        {
            res.push_back(dig);
        }

        return res;
    }
};