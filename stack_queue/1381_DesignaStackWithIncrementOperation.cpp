#include <vector>
#include <stack>


class CustomStack
{
public:
    std::vector<int> stk;
    int capacity;
    int len;

    CustomStack(int maxSize)
    {
        stk = std::vector<int>(maxSize);
        capacity = maxSize;
        len = 0;
    }

    void push(int x)
    {
        if (len == capacity) return;
        stk[len] = x;

        len++;
    }

    int pop()
    {
        if (len == 0) return -1;

        int res = stk[len - 1];
        stk[len - 1] = 0;
        len--;
        return res;
    }

    void increment(int k, int val)
    {
        int numItems = std::min(k, len);
        for (int i = numItems - 1; i >= 0; i--)
        {
            stk[i] += val;
        }
    }
};

//lazy operation
class CustomStack
{
public:
    vector<int> increments;
    stack<int> stk;
    int capacity;

    CustomStack(int maxSize)
    {
        capacity = maxSize;
        increments = vector<int>(capacity);
    }

    void push(int x)
    {
        if (stk.size() == capacity) return;
        stk.push(x);
    }

    int pop()
    {
        if (stk.size() == 0) return -1;
        int i = stk.size() - 1;
        int res = stk.top() + increments[i];
        if (i > 0)
        {
            //carry the previous increment to the next
            increments[i - 1] += increments[i];
        }
        increments[i] = 0;
        stk.pop();
        return res;
    }

    void increment(int k, int val)
    {
        int len = stk.size();
        int i = min(k, len) - 1;
        //no need to add for all elements
        //only flag the last element
        //all the elemets before it, will be incremented when pop the item
        if (i >= 0)
            increments[i] += val;

    }
};
