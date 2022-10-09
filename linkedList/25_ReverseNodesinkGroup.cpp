
/*
Intuition

- get kth node from group start
- reverse one group from group head to kth node
- the first node before revesing is the end of the group,
so connect this node to next group's head
- for iterative solution, connect previous tail to the reversed head\
*/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


/*
Iterative

Time: O(N)
    process each node exactly twice
Space: O(1)

*/

  class Solution_iterative
  {
  public:
      ListNode* findKthNode(ListNode* node, int& k)
      {
          int count = 1;
          while (node && count < k)
          {
              node = node->next;
              count++;
          }
          if (count == k) return node;
          return nullptr;
      }

      ListNode* reverseKGroup(ListNode* head, int k)
      {
          ListNode* dummy = new ListNode(0);
          dummy->next = head;

          ListNode* prevHead = dummy; //previous node of current group's head
          ListNode* nextHead = nullptr;

          while (true)
          {
              ListNode* kthNode = findKthNode(prevHead->next, k);
              if (kthNode == nullptr) break;
              nextHead = kthNode->next;

              //reverse linked list
              //0->(1->2->3)->4->5
              ListNode* prev = nextHead; //1 will point to 4
              ListNode* cur = prevHead->next;

              //(3->2->1)->4->5
              //0->1, 0 still points to 1 after while loop
              while (cur != nextHead)
              {
                  ListNode* temp = cur->next;
                  cur->next = prev;
                  prev = cur;
                  cur = temp;
              }

              //first node of the group before reverse: 1
              ListNode* tem = prevHead->next;
              prevHead->next = kthNode; // 0->(3->2->1)->4->5
              prevHead = tem; //now 1 is end of the group after reversing
              //so set it as previous node of next group

          }

          return dummy->next;
      }
  };

/*
Recursion:

Time: O(N)
process each node exactly twice
Space : O(N / k)

*/

class Solution
{
public:
    ListNode* reverseOneGroup(ListNode* head, ListNode* nextHead)
    {
        //return the new head after reversing
        //1->2->3
        //3->2->1
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nextHead)
        {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* head, int k)
    {
        while (k > 1 && head)
        {
            head = head->next;
            k--;
        }
        if (k == 1) return head;
        return nullptr;

    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        //(1->2->3)->4->5->6->7
        ListNode* groupHead = head;
        ListNode* kthNode = getKthNode(groupHead, k);


        if (kthNode != nullptr)
        {
            ListNode* nextHead = kthNode->next;
            ListNode* reversedHead = reverseOneGroup(groupHead, nextHead);
            //the head is first node before reversing 1->2
            //now is the last node in the group after reversing 2->1
            // 1-> next = next group's head
            head->next = reverseKGroup(nextHead, k);
            return reversedHead;
        }

        return head;


    }
};