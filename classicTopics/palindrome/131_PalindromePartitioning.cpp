#include <string>
#include <vector>

/*
 check google doc notes for drawing

Time Complexity : O(N 2^N)
where N is the length of string s. This is the worst-case time complexity when all the possible substrings are palindrome.
explanation:
1. number of sub string is n+ n-1 + n-2 + n-3 +... = n^2

2. 2^n is number of nodes in the search tree
    - Imagine the string as a sequence of N chars separated by a pipe between neighbors, such as a string "abcde" = a|b|c|d|e
      it has n-1 pipes, in this case 4
    - for each pipe position has 2 choices, put or not put pipe, so 2^n
    - another way of thinking is if we want to select 3 pipe out of 4 is 4 choose 3 = 3
      the total number of ways to partition this example is when we ask all questions "how many ways can I select 0 or 1 or 2 or 3 or 4 pipes.
      4 choose 0 + 4 choose 1 +4 choose 2+ 4 choose 3 + 4 choose 4 = 2^(n-1) = 16

3. for each partition, we do two things:
    - build substring for partition
    - check whether each substring in that partitioning is a palindrome or not
    - Since the number of characters in each partitioning is N, cost of the above operations is N+N = O(N)

4. Combining 2 and 3, we get O(n* 2^n)

Space Complexity: O(N) to store recursion stack

*/

class Solution
{
public:
    std::vector<std::vector<std::string>> res;

    bool isPalindrome(std::string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(std::string& s, int left, std::vector<std::string>& cur)
    {
        if (left == s.length())
        {
            res.push_back(cur);
            return;
        }

        for (int right = left; right < s.length(); right++)
        {
            if (isPalindrome(s, left, right))
            {
                cur.push_back(s.substr(left, right - left + 1));
                dfs(s, right + 1, cur);
                cur.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::string> c;
        dfs(s, 0, c);
        return res;
    }
};

//======================================================
//optimization for check if substring is palindrome using dp
class Solution
{
public:
    std::vector<std::vector<std::string>> res;
    std::vector<std::vector<bool>> isPalinMemo;
    int n;
    //use O(n^2)  to pre calculate palindrome for each substring
    //if check abcba is palindrome, start =0, end =4
    //         ^   ^          
    //check if bcb is palindrome: a(bcb)a
    //                              ^ ^   start+1  end-1
    void createIsPalindromeMemo(std::string& s)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            isPalinMemo[i][i] = true;
            for (int j = i + 1; j <= s.length(); j++)
            {
                if (s[i] == s[j] && (j - i <= 2 || isPalinMemo[i + 1][j - 1]))
                {
                    isPalinMemo[i][j] = true;
                }
            }
        }
    }

    void dfs(std::string& s, int left, std::vector<std::string>& cur)
    {
        if (left == s.length())
        {
            res.push_back(cur);
            return;
        }

        for (int right = left; right < s.length(); right++)
        {
            //it is expensive to check the substring is palindrome
            if (isPalinMemo[left][right])
            {
                cur.push_back(s.substr(left, right - left + 1));
                dfs(s, right + 1, cur);
                cur.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s)
    {
        n = s.length();
        isPalinMemo = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
        createIsPalindromeMemo(s);
        std::vector<std::string> c;
        dfs(s, 0, c);
        return res;
    }
};