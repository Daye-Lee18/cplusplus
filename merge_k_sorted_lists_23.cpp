/*
input: array of "k" linked lists 
    - each linked lists is sorted in ascending order 
output: merge all the linked-lists into one sorted linked-list 

ex) 
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

ex)
Input: lists = []
Output: []

ex)
Input: lists = [[]]
Output: []

*/


#include "linked_list_helper.h"
#include <bits/stdc++.h> 
#include <queue>

using namespace std;


// divide and conquer, heap(priority queue), merge sort 
// input은 head 들이 저장된 vector임 
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    ListNode dummy(0); // dummy의 next를 return 할 것임. 
    ListNode* curr = &dummy; // cur은 iterate하면서 새로운 linked list를 만드는 역할 
    // lambda 
    auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; }; // 작은 것이 priority queue.pop할 때 제일 먼저 빠질 것임 -> min-heap  
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);  // ListNode*를 저장한 heap 저장 

    // minheap에 head node 만 일단 넣어줌 
    for (ListNode* list : lists)
      if (list != nullptr)
        minHeap.push(list);
    
    // minheap에 있는 원소를 빼면서 새로운 curr에 linked list를 구현시켜줌 
    while (!minHeap.empty()) {
      ListNode* minNode = minHeap.top(); // head 들 중에 가장 작은 것, 어차피 기존 linked list가 Sorted 되어 있기 때문에 이렇게 해도 상관없다. 
      minHeap.pop();
      if (minNode->next) // 항상 그 뒤의 노드가 nullptr이 아닌지 체크해야한다 
        minHeap.push(minNode->next);
      curr->next = minNode;
      curr = curr->next;
    }

    return dummy.next;
  }
};


int main() {
    // Create two sorted linked lists
    std::vector<int> arr1 = {1, 4, 5};
    std::vector<int> arr2 = {1, 3, 4};
    std::vector<int> arr3 = {2,6};
    
    ListNode* list1 = createLinkedList(arr1);
    ListNode* list2 = createLinkedList(arr2);
    ListNode* list3 = createLinkedList(arr3);

    // Create a Solution object
    Solution solution;

    vector<ListNode*> my_vec = {list1, list2, list3};
    // Merge the two linked lists
    ListNode* mergedList = solution.mergeKLists(my_vec);

    // Print the merged result
    std::cout << "Merged List: ";
    printLinkedList(mergedList);

    // Clean up memory (delete the linked lists)
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}