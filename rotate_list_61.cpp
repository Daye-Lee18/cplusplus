/*
input: head of linked list 
output: head of roated linked list 

ex) 

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

*/

// idea : two pointers 

#include "linked_list_helper.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0)
      return head;

    // 현재 linked list의 tail을 찾아 head와 연결시켜 circle을 만든다. 
    // 이 때 linked list의 길이도 구한다. 
    ListNode* tail;
    int length = 1;
    for (tail = head; tail->next; tail = tail->next)
      ++length;
    tail->next = head;  // Circle the list

    //  | <---- length -k ----> | <--k-->| 
    // 현재 tail이 맨 끝에 있는데, 이를 length-k만큼 돌면 k는 length-k 구역에 있는 맨 마지막 노드가 된다. 
    const int t = length - (k % length); // k < length보다 작으면 그냥 k가 나옴 
    for (int i = 0; i < t; ++i)
      tail = tail->next;
    
    // 새로운 head를 k 구역에 있는 첫번째 노드로 지정한다. 
    ListNode* newHead = tail->next;
    // tail의 next node를 nullptr로 지정한다. 
    tail->next = nullptr;

    return newHead;
  }
};


int main() {
    // Create two sorted linked lists
    std::vector<int> arr1 = {1, 2, 3 ,4 ,5};
    
    ListNode* list1 = createLinkedList(arr1);
  

    // Create a Solution object
    Solution solution;
    int k =2;

    // Merge the two linked lists
    ListNode* rotatelist = solution.rotateRight(list1, k);

    printLinkedList(rotatelist);

    // Clean up memory (delete the linked lists)
    while (rotatelist != nullptr) {
        ListNode* temp = rotatelist;
        rotatelist = rotatelist->next;
        delete temp;
    }

    return 0;
}