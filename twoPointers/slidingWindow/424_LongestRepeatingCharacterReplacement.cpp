#include <string>
#include <vector>
#include <algorithm>
/*
intuition
- sliding window, this is a standard version and easier to understand, it can be improved to O(n)
- start left and right pointer at 0, get most frequent char in the window.
- check most frequent char is <k, otherwise shift left pointer

complexity:
time O(26*n)
Space O(26)
*/

class Solution
{
    //https://www.youtube.com/watch?v=gqXU1UyA8pk
    //https://www.youtube.com/watch?v=mrPmfnq9Mk8
public:
    int characterReplacement(std::string s, int k)
    {
        int n = s.length();
        int left = 0;
        std::vector<int> freq(26);
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < n; right++)
        {
            freq[s[right] - 'A']++;

            maxFreq = *max_element(freq.begin(), freq.end());
            //right-left+1 is window length
            //-maxFreq to get min number of characters to change, if it is bigger than k, means not valid to change
            //shift left pointer
            while (right - left + 1 - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
                maxFreq = *max_element(freq.begin(), freq.end()); //update in while loop, because freq changes in while loop
            }

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};


/*
Optimization to O(n)
*/

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        std::vector<int> freq(26);
        int n = s.length();
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < n; right++)
        {
            freq[s[right] - 'A']++;
            //instead of loop 26 in array to get max
            //compare maxFreq with last updated char
            //result will only be updated when find a new maxFreq
            
            //we want to maximize len because it is the result
            //we also want to maximize maxFreq to satisfy len-maxFreq <= k, since k is constant
            //so when freq is smaller than maxFreq, it doesn't matter, we over estimate it to a bigger value
            //if we increase len from 6 to 7, it also requires maxFreq to increase to maintain <= k
            maxFreq = std::max(maxFreq, freq[s[right] - 'A']);

            while (right - left + 1 - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};