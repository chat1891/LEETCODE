#include <cstddef>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

/*
- use fast and slow pointer to get to middle of the list
- reverse second half of the list
- loop again to compare first half and reversed second half

1->2->5->2->1
first half: 1->2->5
second half : 5->2->1
reversed second half: 1->2->5


Time O(n)
Space O(1)
*/
class Solution
{
public:
    ListNode* reverseList(ListNode* node)
    {
        ListNode* prev = NULL;
        while (node)
        {
            //5->null
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }

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

    bool isPalindrome(ListNode* head)
    {
        //begin head = 1->2->5->2->1
        //second half: 5->2->1
        ListNode* secondHalf = endOfFirstHalf(head); 
        //after reverse, reversed half : 1->2->5
        //head: 1->2->5->null
        ListNode* reversedHalf = reverseList(secondHalf);

        while (reversedHalf && head)
        {
            if (reversedHalf->val != head->val)
            {
                return false;
            }
            reversedHalf = reversedHalf->next;
            head = head->next;
        }
        return true;
    }
};

/*
approach 2:
- convert linked list to array
- use two pointer in array

cons: space is O(N)
*/