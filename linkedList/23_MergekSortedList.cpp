#include <string>
#include <tuple>
#include <algorithm> 
#include <queue>


 //Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_priorityQueue
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        //use priority queue
        //insert pair<first value, list indedx> to priority queue
        //move that list's first value to next
        //pq only keeps first item of every node in list
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            //**here need to check null for[[]]
            if (lists[i] != nullptr)
            {
                int curVal = lists[i]->val;
                lists[i] = lists[i]->next;
                pq.push({ curVal, i });
            }
        }

        ListNode* root = new ListNode(0);
        ListNode* node = root;
        while (!pq.empty())
        {
            std::pair<int, int> cur = pq.top();
            pq.pop();
            ListNode* curNode = new ListNode(cur.first);
            node->next = curNode;
            node = node->next;

            //add the next value in that list to pq
            if (lists[cur.second] != nullptr)
            {
                pq.push({ lists[cur.second]->val,cur.second });
                lists[cur.second] = lists[cur.second]->next;
            }

        }

        return root->next;
    }
};

//divide and conquer
