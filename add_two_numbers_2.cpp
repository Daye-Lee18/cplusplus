/*
input: two non-empty linked list 
    - the  digits are stored in reversed order 
    - ex) 342 = 2 -> 4 -> 3 
output: linked of sum of two linked list in correct order 

ex) 

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/

#include <iostream>
#include "linked_list_helper.h"

using namespace std;


// pointer 가 input 
// input이 이미 reversed 되어 있어서 순서대로 더해주면 됨. 
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            // return linked list도 역순으로 되어 있어야 함. 처음 계산한 것이 맨 앞에 있어야 함 
            ListNode dummy; // 나중에 return할때 맨 처음을 가리키는 pointer 필요 
            ListNode* cur = &dummy;

            while (l1 || l2 || carry != 0){
                if (l1){
                    carry += l1 -> val;
                    l1 = l1 -> next ;
                }
                if (l2) {
                    carry += l2 -> val;
                    l2 = l2 -> next;
                }
                cur -> next = new ListNode(carry % 10); // 어차피 dummy -> next 를 반환할 거라서 첫 value를 cur -> next에 생성해도 괜찮다. 
                carry = carry / 10;
                cur = cur -> next ;
                
            }
            // dummy가 pointer인 경우 -> 으로 member variable/function에 접근하는데
            // dummy가 variable인 경우 (현재) 에는 '.' 으로 접근한다. 
            return dummy.next ;
    }
};

int main(){

    Solution x;
    ListNode *l1 = new ListNode(2);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);

    ListNode* head = x.addTwoNumbers(l1, l2);
    
    while (head){
        cout << head -> val << " -> ";
        head = head -> next;
    }
    cout << '\n';

    delete l1;
    delete l1 -> next;
    delete l1 -> next -> next ;
    delete l2;
    delete l2 -> next; 
    delete l2 -> next -> next; 

    return 0;
}