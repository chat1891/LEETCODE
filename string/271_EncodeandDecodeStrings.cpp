#include <string>
#include <sstream>
#include <vector>


/*
- add length to the beginning of the string to know where each word ends
- add # to indicate length number ends
*/
class Codec
{
public:

    // Encodes a list of strings to a single string.
    std::string encode(std::vector<string>& strs)
    {
        std::stringstream ss;
        for (auto& s : strs)
        {
            int len = s.length();
            //use # as a separator to show length of string
            ss << len << '#' << s;
        }
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(std::string s)
    {
        int n = s.length();
        std::vector<std::string> res;
        int i = 0;
        while (i < n)
        {
            std::stringstream numStr;
            while (i < n && s[i] != '#')
            {
                numStr << s[i];
                i++;
            }
            i++;
            int len = stoi(numStr.str());
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};


//===================================================
class Codec
{
public:

    // Encodes a list of strings to a single string.
    std::string encode(std::vector<std::string>& strs)
    {
        std::stringstream res;
        for (auto str : strs)
        {
            int length = str.length();
            if (length < 10)
            {
                //because max length is <200, if length is single number add two zeros to make it three
                //so all the length is 3 digits
                res << "0" << "0" << str.length() << str;

            }
            else if (length < 100)
            {
                res << "0" << str.length() << str;
            }
            else
            {
                res << str.length() << str;
            }
        }
        return res.str();
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(std::string s)
    {
        int pos = 0;
        std::vector<std::string> results;
        while (pos < s.length())
        {
            int strLength = std::stoi(s.substr(pos, 3));
            pos += 3;
            std::string currentStr = s.substr(pos, strLength);
            pos += strLength;
            results.push_back(currentStr);

        }
        return results;
    }
};