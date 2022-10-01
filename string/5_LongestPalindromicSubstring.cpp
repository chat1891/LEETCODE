#include <string>
using namespace std;
#include <tuple>
#include <algorithm>
#include<iostream>

//if using brute force
//Time is O(n^3)
//because checking each each substring is n
//number of total substrings: O(n^2)
//for(int i=0 to n){
//  i=0 -> 1+2+3+4+..+n
// i=1-> 1+2+3+4+...+n-1
// i=2 -> 1+2+3+4+...+n-2
//}

class Solution
{
public:

    //return start, end index, length of sub string
    std::tuple<int, int, int> ValidPalindromFromMiddle(int left, int right, string& s)
    {
        if (s == "" || left > right) return { 0,0,0 };
        if (s[left] != s[right]) return{ 0,0,0 }; //if from start, the i and i+1 case is not the same, don't calculate length

        bool hasExtra = false;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }

        //added extra left and right in while loop
        left++;
        right--;
        int len = right - left + 1;
        return { left,right,len };
    }

    string longestPalindrome(string s)
    {

        int start = 0;
        int end = 0;
        int resLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //tie(start1, end1, len1) = ValidPalindromFromMiddle(i, i, s);
            auto [start1, end1, len1] = ValidPalindromFromMiddle(i, i, s); //"abbcbba" -> from c to expand, expand i,i
            auto [start2, end2, len2] = ValidPalindromFromMiddle(i, i + 1, s); //"abba" -> expand i=1,i+1=2 for two b

            int len = max(len1, len2);
            bool len1Bigger = len1 > len2;
            if (len > resLen)
            {
                if (len1Bigger)
                {
                    start = start1;
                    end = end1;
                    resLen = end - start + 1;
                }
                else
                {
                    start = start2;
                    end = end2;
                    resLen = end - start + 1;
                }
            }
            

        }

        return s.substr(start, resLen);


    }
};


//--------------other explaination
class Solution_2
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 1) return s;
        int len = 0, curlen = 0;
        int start = 0;

        // For a string of odd length there is only one middle char, and for even length there are two middle characters
        // For any index in the string there can be one of above conditions true
        // We try to find the longest palidrome using these conditions
        for (int idx = 0; idx < s.size() - 1; idx++)
        {
            int len1 = helper(idx, idx, s); // if length of palindrome is odd
            int len2 = helper(idx, idx + 1, s); // if length of palindrome is even
            curlen = max(len1, len2);
            if (curlen > len)
            {   // if the length of current palindrome is greater the max len we have already calculated 
                len = curlen;
                start = idx - ((len - 1) >> 1); // len-1 because in case of even size palindrome the middle element is already a part of left half, then we have to move len/2-1 steps back to find start index
                // in case of odd we have move len/2 steps back to find start
            }
        }

        return s.substr(start, len);
    }

    int helper(int left, int right, string& s)
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