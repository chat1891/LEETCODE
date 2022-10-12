#include <string>
#include <sstream>
#include <vector>


class Solution_1
{
public:
    std::string reorderSpaces(std::string text)
    {
        std::vector<std::string> words;
        std::stringstream ss;
        int n = text.size();
        int space = 0;
        //different ways to parse string
        for (int i = 0; i < n; i++)
        {
            if (text[i] == ' ')
            {
                space++;
                continue;
            }
            int len = 0;
            int start = i;
            while (i < n && text[i] != ' ')
            {
                len++;
                i++;
            }
            words.push_back(text.substr(start, len));
            //**need to add space count here
            if (text[i] == ' ') space++;
        }


        int gap = words.size() - 1;
        if (gap == 0)
        {
            //for only one word
            return words[0] + std::string(space, ' ');
        }

        //calculate for more than one word
        int extra = space % gap;
        int numSpaces = space / gap;

        for (int i = 0; i < words.size(); i++)
        {
            ss << words[i];
            if (i != words.size() - 1)
            {
                ss << std::string(numSpaces, ' ');
            }
            else
            {
                ss << std::string(extra, ' ');
            }
        }

        return ss.str();
    }
};

class Solution
{
public:
    std::string reorderSpaces(std::string text)
    {
        std::vector<std::string> words;
        std::stringstream ss;
        int n = text.size();
        int space = 0;
        std::string word;
        //second ways to parse string
        for (int i = 0; i < n; i++)
        {
            if (text[i] == ' ')
            {
                space++;
                if (!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
            else
                word += text[i];
        }
        //**need to add last word
        if (!word.empty())
            words.push_back(word);


        int gap = words.size() - 1;
        if (gap == 0)
        {
            //for only one word
            return words[0] + std::string(space, ' ');
        }

        //calculate for more than one word
        int extra = space % gap;
        int numSpaces = space / gap;

        for (int i = 0; i < words.size(); i++)
        {
            ss << words[i];
            if (i != words.size() - 1)
            {
                ss << std::string(numSpaces, ' ');
            }
            else
            {
                ss << std::string(extra, ' ');
            }
        }

        return ss.str();
    }
};