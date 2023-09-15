/*
input: head of singly linked list sorted in ascending order 
output: a height-balaneced binary search tree 
    - A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one

ex) 
head = [-10, -3, 0, 5, 9]
output = [0, -3, 9, -10, null, 5]
*/


#include "binary_search_tree_helper.h"

class Solution{
    public:
        TreeNode* sortedListToBST(ListNode* head){
            if (head == nullptr){
                return nullptr;
            }

            // head -> next == nullptr 
            if (!head -> next){
                return new TreeNode(head->val);
            }

            ListNode* mid = findMid(head);
            TreeNode* root = new TreeNode(mid -> val);
            root -> left = sortedListToBST(head);
            root -> right = sortedListToBST(mid -> next);

            return root;
        }
    private:
        ListNode* findMid(ListNode* head){
            ListNode* prev = nullptr;
            ListNode* slow = head;
            ListNode* fast = head;

            while (fast && fast -> next){
                prev = slow;
                slow = slow -> next;
                fast = fast -> next -> next; 
            }

            prev -> next = nullptr; 

            return slow;
        }
};