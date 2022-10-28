#include <cstddef>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* endOfFirstHalf(ListNode* node)
{
    ListNode* fast = node;
    ListNode* slow = node;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* node)
{
    ListNode* prev = NULL;
    while (node)
    {
        ListNode* temp = node->next;
        node->next = prev;
        prev = node;
        node = temp;
    }
    return prev;
}