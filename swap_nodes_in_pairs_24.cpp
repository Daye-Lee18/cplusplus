/*
input: linked list 
output: head of new linked list that every two adjacent nodes swapped 

ex) 
Input: head = [1,2,3,4]
Output: [2,1,4,3]

ex)
Input: head = []
Output: []

ex)
Input: head = [1]
Output: [1]

*/

#include <bits/stdc++.h>
#include "linked_list_helper.h"

using namespace std;


// linked list는 항상 다음 노드가 있는지 체크할 필요가 있다. 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* fast = & dummy;
        while (fast -> next && fast -> next -> next){
            swap(fast, fast->next);
            fast = fast -> next ->next ;  
        }
        return dummy.next;
    }
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    const int length = getLength(head);
    ListNode dummy(0, head); // dummy의 next를 head로 둠 (나중에 return할 pointer)
    // prev, curr 초기화  
    ListNode* prev = &dummy;
    ListNode* curr = head;


    for (int i = 0; i < length / 2; ++i) {
      ListNode* next = curr->next; // next는 loop안에서 항상 지금의 (curr)의 next로 초기화 및 update 해준다. 
      // pre -> cur -> next -> next.next 가 있다
      // pre -> 1 -> 2 -> 3 -> 4 
      // pre -> 2 -> 1 -> 3 -> 4 로 바꿔주려면 3개의 pointer를 바꿔줘야 함. 
      // 아래는 3개의 포인터를 순차적으로 바꿔주는 것이다.
      // 이 때 중요한 것은 자신이 업데이트 되기 전에 먼저 자신의 값으로 update해줘야함. 
      // 예를 들어, next->next가 업데이트 되기 전, curr -> next = next -> next;로 assign해준다 
      curr->next = next->next; 
      next->next = prev->next; 
      prev->next = next; 
      
      // 다음 step으로 이동 
      prev = curr;  
      curr = curr->next; 
    }

    return dummy.next;
  }

 private:
  int getLength(ListNode* head) {
    int length = 0;
    for (ListNode* curr = head; curr; curr = curr->next)
      ++length;
    return length;
  }
};

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
   
    
    ListNode* list1 = createLinkedList(arr1);

    // Create a Solution object
    Solution solution;

    // Merge the two linked lists
    ListNode* swappedlist = solution.swapPairs(list1);

    // Print the merged result
    printLinkedList(swappedlist);

    // Clean up memory (delete the linked lists)
    while (swappedlist != nullptr) {
        ListNode* temp = swappedlist;
        swappedlist = swappedlist->next;
        delete temp;
    }

    return 0;
}