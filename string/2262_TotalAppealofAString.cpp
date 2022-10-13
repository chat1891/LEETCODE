#include <vector>
#include<string>

/*

similar to 828. Count Unique Characters of All Substrings of a Given String.

In a substring, multiple same character only get one point.
We can consider that the first occurrence get the point.
Now for each character, we count its contribution for all substring.

**Intuition**
for each character s[i], to include character s[i] in substring,
it must start before s[i] to contain s[i] till previous occurrence of the character.
it ends at last position of the entire string.

In total, it has `i - previous occurrence index` possible start positions, (from previous occurrence to current index)
it has ` n - i ` possible end positions, (from current index to end of string)
so total possibilities are `(i - prevOccurrence[s[i]]) * (n - i)`

**For example**
abbca
- i=0: (a)b)b)c)a) = (0-(-1)) *(5-0) =5
- i=1: (a(b)b)c)a) = (1-(-1)) *(5-1) = 2*4 = 8
- i=2: ab(b)c)a) = (2-(1)) *(5-2) = 1*3 = 3 //previous b is i=1
- i=3: (a(b(b(c)a) = (3-(-1)) *(5-3) = 4*2 = 8
- i=4: a(b(b(c(a) = (4-0) *(5-4) = 4*1 = 4 //previous a is i=0

**Complexity**
Time complexity: O(n)
Space complexity: O(26)



Complexity: 
Time O(n), 
Space O(26)
*/

class Solution
{
public:
    long long appealSum(std::string s)
    {
        std::vector<int> prevOccurrence(26, -1);
        long long res = 0;
        int n = s.length();

        for (int i = 0; i < s.length(); i++)
        {
            int j = s[i] - 'a';
            int count = (i - prevOccurrence[j]) * (n - i);
            res += count;
            prevOccurrence[j] = i;
        }

        return res;
    }
};