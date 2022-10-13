#include <vector>
#include <unordered_map>
#include <string>

//https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/128952/JavaC%2B%2BPython-One-pass-O(N)

//similar to 2262. Total Appeal of A String


/*
Intuition
Let's think about how a character can be found as a unique character.

Think about string "XAXAXXAX" and focus on making the second "A" a unique character.
We can take "XA(XAXX)AX" and between "()" is our substring.
We can see here, to make the second "A" counted as a unique character, we need to:

insert "(" somewhere between the first and second A
insert ")" somewhere between the second and third A
For step 1 we have "A(XA" and "AX(A", 2 possibility.
For step 2 we have "A)XXA", "AX)XA" and "AXX)A", 3 possibilities.

So there are in total 2 * 3 = 6 ways to make the second A a unique character in a substring.
In other words, there are only 6 substring, in which this A contribute 1 point as unique string.

Instead of counting all unique characters and struggling with all possible substrings,
we can count for every char in S, how many ways to be found as a unique char.
We count and sum, and it will be out answer.


Explanation
index[26][2] record last two occurrence index for every upper characters.
Initialise all values in index to -1.
Loop on string S, for every character c, update its last two occurrence index to index[c].
Count when loop. For example, if "A" appears twice at index 3, 6, 9 seperately, we need to count:
X X X A X X A X X A
0 1 2 3 4 5 6 7 8 9
For the first "A": (X (X (X (A) X) X) A X X A
    (6-3) * (3-(-1))" -> (next index - cur index) * (cur index - prev index)
For the second "A": X X X A (X (X (A) X) X) A
    (9-6) * (6-3)"
For the third "A": X X X A X X A (X (X (A)
    (N-9) * (9-6)"



Complexity
One pass, time complexity O(N).
Space complexity O(1).

*/


class Solution
{
public:
    int uniqueLetterString(std::string s)
    {
        long long res = 0;
        std::unordered_map<char, std::vector<int>> mp; // char, list of index of char
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            mp[s[i]].push_back(i);
        }

        for (auto& ch : mp)
        {
            int prev = -1;//prev starts with -1           
            int num = ch.second.size();
            for (int i = 0; i < num; i++)
            {
                int cur = ch.second[i];

                if (i != num - 1)
                {
                    //for first occurrence
                    // prev index is -1
                    //(cur index - prev index) * (next index * cur index)
                    res += (cur - prev) * (ch.second[i + 1] - cur);
                    prev = cur;
                }
                else
                {
                    //for the last occurrence
                    //next is n
                    res += (cur - prev) * (n - cur);
                }
            }
        }

        return res;
    }
};