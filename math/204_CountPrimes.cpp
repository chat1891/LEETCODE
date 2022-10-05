#include<vector>

//Sieve of Eratosthenes
//logic:
//-start with the smallest prime number we know, which is 2
//- We mark the multiples of this number as non-primes in the array.


class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2) return 0;
        std::vector<bool> numbers(n, false);
        int count = 0;

        //use square root, It is not necessary to consider any number greater than the square root of n. 
        //if n =30, sqrt(n) = 6
        //6 * 1 = 6 = 1 * 6 -> covered by 1
        //6 * 2 = 12 = 2 * 6 -> covered by 2
        //6 * 3 = 18 = 3 * 6 -> covered by 3
        //6 * 4 = 24 = 2 * 12
        //6 * 5 = 30 = 5 * 6
        //6 * 6 = 36 > 30
        for (int i = 2; i < sqrt(n); i++)
        {
            if (!numbers[i])
            {
                //every multiple of 6 was already addressed by some multiple of a prime number less than 6.
                for (int num = i * i; num < n; num += i)
                {
                    numbers[num] = true;
                }
            }
        }

        for (int i = 2; i < n; i++)
        {
            if (!numbers[i])
            {
                count++;
            }
        }
        return count;
    }
};