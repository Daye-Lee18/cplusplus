/*
input : head of linked list , integer n 
output: linked list head with nth node removed 


ex) 

Input: head = [1], n = 1
Output: []

ex) 
Input: head = [1,2,3,4,5], n = 2 
Output: [1,2,3,5] // 뒤에서부터 2번째 것이 제거됨 

*/

#include <iostream>
#include "linked_list_helper.h"
using namespace std;


// two pointers 
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;
    // n-- 는 현재 값 2 다음은 1 그 다음은 0이렇게 됨 (return first and evaluation)
    // node: 1-> 2 (fast-> next) > 3 (fast->next->next)에서 멈춤 
    while (n--)
      fast = fast->next;

    // 지워야 하는 전 node가 이미 nullptr이면...
    if (fast == nullptr)
      return head->next;

    // 만약 지워야 하는 node의 다음이 존재한다면, 
    // fast가 tail일 때 까지 간다면, """fast와 slow의 차이는 n""" 만큼 존재해야 지워야 하는 노드 바로 앞에 slow를 만들 수 있다. |--------slow-> ----n---> fast(tail)|
    // 따라서 맨 앞에서 fast 혼자 먼저 n번 만큼 먼저 진행해준다. 
    while (fast->next) {
      slow = slow->next; // 2 -> 3 
      fast = fast->next; // 4 -> 5 
    }

    slow->next = slow->next->next; // 3의 next를 4가 아니고 5를 가리키도록 함. 

    return head;
  }
};


int main(){

    Solution x;
    ListNode *l1 = new ListNode(1);
    l1 -> next = new ListNode(2);
    l1 -> next -> next = new ListNode(3);
    l1 -> next -> next -> next = new ListNode(4);
    l1 -> next -> next -> next -> next = new ListNode(5);

    ListNode* head = x.removeNthFromEnd(l1, 2);
    
    while (head){
        cout << head -> val << " -> ";
        head = head -> next;
    }
    cout << '\n';

    delete l1;
    delete l1 -> next;
    delete l1 -> next -> next ;
    delete l1 -> next -> next -> next; 
    delete l1 -> next -> next -> next -> next ; 
    return 0;
}