#include <string>
#include <vector>
using namespace std;

//vertical comparison
//for each string
//compare from index 0 to whatever, till it doesn't match

/// <summary>
/// time complexity O(S) -> s is sum of all number of character in the string list
/// space complexity O(1)
/// </summary>
class Solution_verticalComparison
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res;
        int longestStrLen = 200;
        int i = 0;
        bool isValid = true;

        for (; i < longestStrLen; i++)
        {
            char curChar;
            if (i < strs[0].length())
            {
                curChar = strs[0][i];
            }
            else
            {
                break;
            }

            for (int j = 0; j < strs.size(); j++)
            {
                string curStr = strs[j];
                if (!(i < curStr.length() && curStr[i] == curChar))
                {
                    isValid = false;
                    break;
                }
            }

            if (!isValid)
            {
                break;
            }
        }

        return strs[0].substr(0, i);
    }
};


//binary search

//Time complexity : O(S*logm), where S is the sum of all characters in all strings.
//The algorithm makes logm iterations, for each of them there are S=m*n comparisons, 
//which gives in total O(S*logm) time complexity.
class Solutionbinary_search
{
public:
    bool PrefixIsValid(int start, int end, vector<string>& strs)
    {
        int len = end - start + 1;
        string curPrefix = strs[0].substr(start, len);
        for (int i = 0; i < strs.size(); i++)
        {

            if (strs[i].substr(start, len) != curPrefix)
            {
                return false;
            }
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        int maxPrefix = 0;
        int minLen = INT_MAX;
        for (auto str : strs)
        {
            int strLen = str.length();
            minLen = min(minLen, strLen);
            //minLen = minLen>str.length()? str.length() : minLen;
        }

        int left = 0;
        int right = minLen - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (PrefixIsValid(left, mid, strs))
            {
                maxPrefix += (mid - left + 1);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }

        return strs[0].substr(0, maxPrefix);
    }
};