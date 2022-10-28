#include <string>
#include <tuple>
#include <algorithm>
#include<iostream>
#include <vector>

//similar questions
//516. Longest Palindromic Subsequence
//647. Palindromic Substrings
//1216. Valid Palindrome III
//1143. Longest Common Subsequence


//if using brute force
//Time is O(n^3)
//because checking each each substring is n
//number of total substrings: O(n^2)
//for(int i=0 to n){
//  i=0 -> 1+2+3+4+..+n
// i=1-> 1+2+3+4+...+n-1
// i=2 -> 1+2+3+4+...+n-2
//}


//=======================================
/*
- for each char from i=0 to n
- expand from center to left and right
- ac(b)ca
  a(cbc)a
  (acbca)

*/
class Solution
{
public:
    int n;

    std::tuple<int, int> checkPalindrome(std::string& s, int l, int r)
    {
        while (l >= 0 && r < n && s[l] == s[r])
        {
            l--;
            r++;
        }
        //added extra left and right in while loop
        l++;
        r--;
        return { l,r - l + 1 };
    }

    std::string longestPalindrome(std::string s)
    {
        n = s.length();
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            //if length is odd
            //"abbcbba" -> from c to expand, expand i,i
            auto [l1, len1] = checkPalindrome(s, i, i);
            //if length is even
            //"abba" -> expand i=1,i+1=2 for two b
            auto [l2, len2] = checkPalindrome(s, i, i + 1);

            int len = std::max(len1, len2);
            if (len > maxLen)
            {
                maxLen = len;
                if (len1 > len2)
                {
                    start = l1;
                }
                else
                {
                    start = l2;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};


//--------------other explanation
class Solution_2
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.size() == 1) return s;
        int len = 0, curlen = 0;
        int start = 0;

        // For a string of odd length there is only one middle char, and for even length there are two middle characters
        // For any index in the string there can be one of above conditions true
        // We try to find the longest palindrome using these conditions
        for (int idx = 0; idx < s.size() - 1; idx++)
        {
            int len1 = helper(idx, idx, s); // if length of palindrome is odd
            int len2 = helper(idx, idx + 1, s); // if length of palindrome is even
            curlen = std::max(len1, len2);
            if (curlen > len)
            {   // if the length of current palindrome is greater the max len we have already calculated 
                len = curlen;
                start = idx - ((len - 1) >> 1); // len-1 because in case of even size palindrome the middle element is already a part of left half, then we have to move len/2-1 steps back to find start index
                // in case of odd we have move len/2 steps back to find start
            }
        }

        return s.substr(start, len);
    }

    int helper(int left, int right, std::string& s)
    { // traversing from middle to both sides till the palandome is compelete
        if (left > right) return 0;

        while (left >= 0 and right < s.size() and s[left] == s[right])
        { //if the current value at indexes are matching we move one step back, on left and one step forward, on right, till the loop condition agrees
            --left;
            ++right;

        }

        return right - left - 1; // length of palindrome we traversed
    }
};


/*
    aabaa
    when i == 2
    helper(i, i, s) returns length 5;

    abba
    when i == 1
    helper(i, i+1, s) returns length 4;

*/


//=================================================
//dp top down recommended fill up top right triangle
/*
row = i; column = j, substring from i to j
//fill in from bottom to up, at each level from left to right
//P(i,j) = (P(i+1,j-1) && s[i]==s[j])
//P(1,3) = "aba" = P(2,2) && s[1] = s[3]

      j
      b a b a d
i   b T F T F F     ^   b, ba, bab, baba, babad
    a   T F T F     ^   a, ab, aba, abad
    b     T F F     ^   b, ba, bad 
    a       T F     ^   a, ad
    d         T     ^   d


    Time Complexity - O(N^2), 
    Space Complexity - O(N^2) (caching all substring)
*/
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        int n = s.length();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));
        int start = 0;
        int end = 0;

        //every single character itself is a palindrome
        for (int i = 0; i < n; i++)
        {
            memo[i][i] = true;
        }
        //bottom up
        //i is start, j is end
        //check if sub starting from i to j is palindrome
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its substring is palindrome.
                   //a(bab)a
                   //i=0, j = 4 ->
                   //[i+1][j-1]=from 1 to 3: aba

                   //j-i ==2: aba
                   //j-i ==1 : bb
                    if (j - i == 1 || memo[i + 1][j - 1])
                    {
                        memo[i][j] = true;

                        //check length
                        if (end - start < j - i)
                        {
                            start = i;
                            end = j;
                        }
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);

    }
};