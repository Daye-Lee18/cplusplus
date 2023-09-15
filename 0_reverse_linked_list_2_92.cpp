/*
input : head of linked list , integer left, right 
    - left <= right 
    - if left == right:
        - Input: head = [5], left = 1, right = 1
        - Output: [5]
output: reversed linked list from position left to right 
    - starting index = 1 

ex) 
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

*/

#include <bits/stdc++.h>
#include "linked_list_helper.h"

using namespace std;

// recursive 

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == 1)
      return reverseN(head, right);

    head->next = reverseBetween(head->next, left - 1, right - 1);

    return head;
  }

 private:
  ListNode* reverseN(ListNode* head, int n) {
    if (n == 1)
      return head;
    
    ListNode* newHead = reverseN(head->next, n - 1);
    ListNode* headNext = head->next;
    head->next = headNext->next;
    headNext->next = head;

    return newHead;
  }
};


// iterative 
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || m == n)
      return head;

    ListNode dummy(0, head);
    ListNode* prev = &dummy;

    for (int i = 0; i < m - 1; ++i)
      prev = prev->next;  // Point to the node before the sublist [m, n]

    ListNode* tail = prev->next;  // Will be the tail of the sublist [m, n]

    // Reverse the sublist [m, n] one by one
    for (int i = 0; i < n - m; ++i) {
      ListNode* cache = tail->next;
      tail->next = cache->next;
      cache->next = prev->next;
      prev->next = cache;
    }

    return dummy.next;
  }
};

