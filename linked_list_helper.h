#pragma once 

#include <iostream>
#include <vector> 
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Function to create a linked list from an array of integers
ListNode* createLinkedList(const std::vector<int>& arr) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int val : arr) {
        if (head == nullptr) {
            // Create the head node if it doesn't exist
            head = new ListNode(val);
            current = head;
        } else {
            // Create a new node and link it to the current node
            current->next = new ListNode(val);
            current = current->next;
        }
    }

    return head;
}
