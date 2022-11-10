/*
- create map mp1 for string and mp2 to store its reverse string if find any
- use same key to store in both map
- get min count find for same key in mp1 and mp2
- result+= min count * length of each string * 2 (symmetric)

- do same thing for mp3 which stores string with same letters (xx)
- however, if mp3 has anything count with odd number, we can put that extra in center


ab: mp1
ba: mp2
    count=min(mp1[key],mp2[key]);
    ret+= count * 2(length of each string) * 2 (symmetric)

aa: mp3
    ret+= count * 2(length of each string)
*/
//https://www.youtube.com/watch?v=Orqh0Pzb7Q0

#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    int longestPalindrome(std::vector<std::string>& words)
    {
        std::unordered_map<std::string, int> mp1;
        std::unordered_map<std::string, int> mp2;
        std::unordered_map<std::string, int> mp3;
        int res = 0;

        for (auto& w1 : words)
        {
            std::string w2 = w1;
            reverse(w2.begin(), w2.end());
            if (w2 == w1)
            {
                mp3[w1]++;
            }
            else
            {
                //want to use same key for ab and ba
                std::string key = min(w1, w2);
                if (key == w1)
                    mp1[key]++;
                else
                    mp2[key]++;
            }

        }

        for (auto& [key, freq] : mp1)
        {
            if (mp2.count(key) != 0)
            {
                int& freq2 = mp2[key];
                //* it is important to take min here
                int count = std::min(freq, freq2);
                res += count * 2 * 2;
            }
        }

        int haveExtraForCenter = false;
        for (auto& [key, freq] : mp3)
        {
            //if there is one is odd number, can put at center
            if (freq % 2 != 0)
                haveExtraForCenter = true;

            //need two to be symmetric
            int k = freq / 2;
            res += k * 2 * 2;
        }

        //["cc","ll","xx"]
        if (haveExtraForCenter)
        {
            //if total is odd number of xx.
            //we can put one in center
            res += 2;
        }

        return res;
    }
};