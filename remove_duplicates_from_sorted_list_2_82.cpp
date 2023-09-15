/*
input: sorted linked list 
output: head of new linked list leaving only distinct numbers from the original list.

ex) 

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/


#include <bits/stdc++.h>
#include "linked_list_helper.h"

using namespace std;

// two pointers 
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;

    while (head) {
      while (head->next && head->val == head->next->val)
        head = head->next;
      
      // 맨 처음에 prev -> next는 head 임 (dummy(0, head))
      if (prev->next == head){
        prev = prev->next; 
      }
      // head는 tail이거나 다음 val랑 같이 않는 곳에서 멈춤으로 값이 안 같은 node는 head -> next이다. 
      else{
        prev->next = head->next;
      }

      // while loop 안에서 heap update 
      head = head->next;
    }

    return dummy.next;
  }
};

int main() {
    // Create two sorted linked lists
    std::vector<int> arr1 = {1, 1, 2, 3 ,3, 5};
    
    ListNode* list1 = createLinkedList(arr1);
  

    // Create a Solution object
    Solution solution;

    // Merge the two linked lists
    ListNode* deletelist = solution.deleteDuplicates(list1);
    printLinkedList(deletelist);

    // Clean up memory (delete the linked lists)
    while (deletelist != nullptr) {
        ListNode* temp = deletelist;
        deletelist = deletelist->next;
        delete temp;
    }

    return 0;
}
