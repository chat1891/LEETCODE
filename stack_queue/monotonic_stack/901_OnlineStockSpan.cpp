#include<stack>


//monotonic stack
//next function: Time O(1)
//space O(n) worse case
class StockSpanner
{
public:
    std::stack<std::pair<int, int>> prices;
    StockSpanner()
    {

    }

    int next(int price)
    {
        int count = 1;

        while (!prices.empty() && prices.top().first <= price)
        {
            count += prices.top().second;
            prices.pop();
        }
        prices.push({ price,count });
        return count;
    }
};