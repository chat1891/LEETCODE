#include <string>

/*
Algorithm

- If the length of the string is 11, return an empty string since we cannot create a non-palindromic string in this case.
- Iterate over the string from left to the middle of the string: if the character is not aa, change it to aa and return the string.
- If we traversed over the whole left part of the string and still haven't got a non-palindromic string, 
it means the string has only a's. Hence, change the last character to b and return the obtained string.

Time: O(N)
Space: O(1)
*/

class Solution
{
public:
    std::string breakPalindrome(std::string palindrome)
    {
        int n = palindrome.length();
        if (n < 2) return "";

        int l = 0;

        while (l < n / 2)
        {
            //change the earliest non a to a can make lexicographically smallest
            if (palindrome[l] > 'a')
            {
                palindrome[l] = 'a';
                return palindrome;
            }
            l++;
        }

        //if string only has a's
        //then change the last character to b
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};