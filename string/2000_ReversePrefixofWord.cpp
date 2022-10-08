#include <string>

class Solution
{
public:
    std::string reversePrefix(std::string word, char ch)
    {
        int endIdx = -1;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ch)
            {
                endIdx = i;
                break;
            }
        }

        if (endIdx == -1) return word;
        int s = 0;
        while (s < endIdx)
        {
            char temp = word[endIdx];
            word[endIdx--] = word[s];
            word[s++] = temp;
        }

        return word;
    }
};