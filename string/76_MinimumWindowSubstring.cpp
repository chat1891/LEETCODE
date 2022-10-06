#include <map>
#include <string>

/*
Logic:
- have two maps for frequency, one is what is needed, one is what we have now in substring
-have a count to count how many chars has met the frequency condition
-after finding enough substring, start shorten the string from left
-break when the condition is no long met
-start to move right pointer again

Time:O(S+T)
- worst case visit S twice, once by left pointer, once by right pointer
-T is length of T

Space: O(T)
*/
//https://www.youtube.com/watch?v=jSto0O4AJbM
class Solution
{
public:
    std::string minWindow(std::string s, std::string t)
    {
        std::map<char, int> needFreq;
        std::map<char, int> haveFreq;
        int count = 0;
        int left = 0;
        int minLen = INT_MAX;
        std::string res;

        for (const char& c : t)
        {
            needFreq[c]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            char& cur = s[i];

            if (needFreq.find(cur) != needFreq.end())
            {
                haveFreq[cur]++;
                //if find enough current letter, add count
                if (haveFreq[cur] == needFreq[cur])
                {
                    count++;
                }
            }

            //start to shorten the string from left
            //untill condition is not met
            while (count == needFreq.size())
            {
                //check length first
                if (i - left + 1 < minLen)
                {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }

                char l = s[left];

                if (needFreq.find(l) != needFreq.end())
                {
                    haveFreq[l]--;
                    //*only if need is bigger than have count--
                    if (needFreq[l] > haveFreq[l])
                    {
                        count--;
                    }
                }
                left++;
            }
        }

        return res;
    }
};