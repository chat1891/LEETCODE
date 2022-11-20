#include <string>
using namespace std;
#include <tuple>
#include <algorithm> 
#include <queue>
#include <unordered_map>


class Solution_recursion
{
public:
    int kthGrammar(int n, int k)
    {

        // base case

        if (n == 1 && k == 1)
            return 0;

        // find the mid

        // length of nth will pow(2, n - 1)

        int mid = pow(2, n - 1) / 2;

        // first half part of nth will be same as of the (n - 1)th

        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }

        // second half part will be complement of (n - 1)th

        else
        {
            return !(kthGrammar(n - 1, k - mid));
        }
    }
};


class Solution_iterative
{
    //https://www.youtube.com/watch?v=TfbfhC3fBGA
public:
    int kthGrammar(int n, int k)
    {
        int half = pow(2, n - 1);
        bool isZero = true;
        while (n > 1)
        {
            half = pow(2, n - 1) / 2;
            if (k > half)
            {
                //only change the sign when it on the right child
                isZero = !isZero;
                //take relative value of k
                k -= half;
            }

            half /= 2;
            n--;
        }

        //because get down to the bottom, only left 1 or 0
        return isZero ? 0 : 1;
    }
};