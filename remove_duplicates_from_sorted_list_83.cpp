/*
input : sorted linked list head in ascending order 
output: a head of linekd list that all duplicates are deleted and all elements are sorted 

ex) 
Input: head = [1,1,2,3,3]
Output: [1,2,3]

*/

#include "linked_list_helper.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr){
            // curr가 아닌 cur -> next를 계속 업데이트 해줌 
            while (curr -> next && curr-> val == curr -> next -> val){
                curr -> next = curr -> next -> next;
            }
            // cur update 
            curr = curr -> next;
        }
        return head;
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