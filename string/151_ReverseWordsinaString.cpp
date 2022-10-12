#include <vector>
#include <string>


//Time: O(n)
//Space: O(1)
class Solution_1
{
public:
    std::string reverseWords(std::string s)
    {
        int n = s.length();
        int start = 0;
        std::string res;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ') continue; //skip space

            //get the word
            start = i;
            while (i < n && s[i] != ' ')
            {
                i++;
            }
            int len = i - start;
            std::string word = s.substr(start, len);
            word += ' ';//add space after each word
            res = word + res; //add word to result in reversed order            
        }

        res.erase(res.size() - 1, 1); //delete extra space added for first word
        return res;

    }
};


//Time: O(n)
//Space: O(n)
class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::vector<std::string> words;
        int n = s.length();
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ') continue;
            start = i;
            while (i < n && s[i] != ' ')
            {
                i++;
            }
            int len = i - start;
            words.push_back(s.substr(start, len));
        }

        std::string res;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            res += words[i];
            if (i != 0) res += ' ';
        }

        return res;

    }
};