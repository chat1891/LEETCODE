#include <unordered_map>
using namespace std;
#include <stack>
#include <concurrent_priority_queue.h>
#include <queue>

class FreqStack
{
public:
    unordered_map<int, stack<int>> freqToElement; //<frequency, elelmet stack>
    unordered_map<int, int> elementToFreq; //<element, frequency>
    int maxFreq = 0;

    FreqStack()
    {

    }

    void push(int val)
    {
        elementToFreq[val]++;
        int curFreq = elementToFreq[val];
        freqToElement[curFreq].push(val);
        maxFreq = max(maxFreq, curFreq);
    }

    int pop()
    {
        int element = freqToElement[maxFreq].top();
        freqToElement[maxFreq].pop();
        if (freqToElement[maxFreq].size() == 0)
        {
            maxFreq--;
        }
        elementToFreq[element]--;
        return element;
    }
};


//custom comparitor of vector
class FreqStack
{
public:
    class comparisonClass
    {
    public:
        bool operator() (const vector<int>& a, const vector<int>& b)
        {
            //if frequency is equal order by index
            return a[1] == b[1] ? b[2] > a[2]:
            b[1] > a[1]; //order by frequency
            //return b[2]<a[2];
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, comparisonClass> pq; //tuple<val, freqency,index>
    //vector<int> positions;
    unordered_map<int, int> elementToFreq;
    int index = 0;

    FreqStack()
    {

    }

    void push(int val)
    {
        int f = ++elementToFreq[val];
        pq.push({ val,f,index++ });
    }

    int pop()
    {
        int item = pq.top()[0];
        int f = pq.top()[1];
        int idx = pq.top()[2];
        //auto[item,f,idx] = pq.top();
        pq.pop();
        elementToFreq[item]--;
        return item;
    }
};

//custom comparitor with tuple
class FreqStack
{
public:
    class comparisonClass
    {
    public:
        bool operator() (const tuple<int, int, int>& a, const tuple<int, int, int>& b)
        {
            auto& [val1, f1, i1] = a;
            auto& [val2, f2, i2] = b;
            //if frequency is equal order by index
            return f1 == f2 ? i2 > i1: f2 > f1;
            //else order by frequency
        }
    };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comparisonClass> pq; //tuple<val, freqency,index>
    unordered_map<int, int> elementToFreq;
    int index = 0;

    FreqStack()
    {

    }

    void push(int val)
    {
        int f = ++elementToFreq[val];
        pq.push({ val,f,index++ });
    }

    int pop()
    {
        auto [item, f, idx] = pq.top();
        pq.pop();
        elementToFreq[item]--;
        return item;
    }
};
