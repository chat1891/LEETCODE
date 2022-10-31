#include <string>
#include <vector>
bool isPalindrome(std::string& s, int l, int r)
{
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

//dp regular template
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