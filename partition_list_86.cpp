/*
input: head of linked list , value x 
output: head of new linked list that is partitioned with respect to value x 
    - the original relative order of the nodes should be preserved 
    - left : less than x 
    - right : greater or equal than x 

ex) 
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

==> 3보다 작은 것 순서 그대로 : 1, 2, 2 
==> 3보다 같거나 큰 것 순서 그대로 : 4, 3, 5 


*/

#include <bits/stdc++.h>
#include "linked_list_helper.h"

using namespace std;

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    // beforeHead와 afterHead는 두 linked list의 맨 앞을 가리키는 variable로 추후에 둘 다 필요  
    ListNode beforeHead(0);
    ListNode afterHead(0);
    ListNode* before = &beforeHead;
    ListNode* after = &afterHead;

    for (; head; head = head->next)
      if (head->val < x) {
        before->next = head; // 현재 before -> next는 nullptr이라 임시방편으로 head로 나준 건가..?
        before = head; // linkedlist에서는 보통 dummy의 next를 반환하므로 dummy -> next부터 update해준다. 
      } else {
        after->next = head;
        after = head;
      }
    
    // connect before, after
    after->next = nullptr;
    before->next = afterHead.next;

    return beforeHead.next; // 항상 next 를 반환 
  };
};
