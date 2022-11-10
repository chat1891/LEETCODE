#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
Algorithm

- Initialize a map where key is the word and value is the length of the longest word sequence possible with the key as the end word.
- Sort the word list in increasing order of the word length.
- Initialize maxLength to 1. This variable holds the length of the longest word sequence possible.
- Iterate over the sorted list.
- For each word initialize presentLength to 1.
- Iterate over the entire length of each word.
  - Delete the character at i-th position from the current word and assign the new word to the variable predecessor.
  - Check if predecessor is present in the list or not.
    - If the predecessor is present, Update the presentLength if previousLength + 1 is greater than the presentLength.
    - update maxLength
*/


/*
Time Complexity:
O(N*logN + N*L^2)
- Let N be the number of words in the list and L be the maximum possible length of a word.
- sort is N LOG(N)
- for each word: N
    - iterate each length L
        - creating predecessor is another L

Space complexity: O(N)
We use a map to store the length of the longest sequence formed with each of the NN words as the end word.
*/


class Solution
{
public:
    int longestStrChain(std::vector<std::string>& words)
    {
        std::unordered_map<std::string, int> dp; //predecessor string, chain length
        sort(words.begin(), words.end(),
            [](const std::string& a, const std::string& b)
            {
                return a.size() < b.size();
            });

        int maxLength = 1;
        for (auto& word : words)
        {
            //*Init to 1
            if (dp.count(word) == 0)
                dp[word] = 1;

            // Find all possible predecessors for the current word by removing one letter at a time.
            for (int i = 0; i < word.length(); i++)
            {
                std::string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(predecessor) != 0)
                {
                    dp[word] = std::max(dp[word], dp[predecessor] + 1);                   
                }
                maxLength = std::max(dp[word], maxLength);
            }
        }
        return maxLength;
    }
};