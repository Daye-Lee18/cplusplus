/*
input: two sorted linked list 
output: merged and sorted linked list head 

ex) 

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

*/

#include <iostream>
#include "linked_list_helper.h"
#include <vector> 

using namespace std;



//idea: recursion, return-based recursion 

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // based case 
    // l1, l2중 하나라도 nullptr인 경우에는 남은 linked list로 채우면 됨.
    if (!list1 || !list2)
      return list1 ? list1 : list2; // (codiontion) ? a : b 
    
    // general case 
    if (list1->val > list2->val) // list1의 head가 항상 더 작도록 swap을 이용함
      swap(list1, list2); // call by reference(&) 로 구현되어 있음
    
    list1->next = mergeTwoLists(list1->next, list2); // return based recursion, 다음 node가 l1에 있을 지 l2에 있을 지 비교 
    
    return list1;
  }
};

int main() {
    // Create two sorted linked lists
    std::vector<int> arr1 = {1, 3, 5};
    std::vector<int> arr2 = {2, 4, 6};
    
    ListNode* list1 = createLinkedList(arr1);
    ListNode* list2 = createLinkedList(arr2);

    // Create a Solution object
    Solution solution;

    // Merge the two linked lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

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
