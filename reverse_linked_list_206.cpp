/*
input: 
output: 



*/

#include "linked_list_helper.h"

// recursive method 
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)
      return head;

    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};

// iterative method 
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;

    while (head) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};



