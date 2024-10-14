#include <iostream>

class ListNode {
    public:
    int val = 0;
    ListNode *next;

    ListNode(int value) {
        this->val = value;
        next = nullptr;
    }
};

class Solution {
    public:
    /**
     * Reverse a LinkedList (easy)
     * 
     * Given the head of a Singly LinkedList, reverse the LinkedList. 
     * Write a function to return the new head of the reversed LinkedList.
     * 
     * Original: head -> [ ] -> [ ] -> [ ] -> [ ] -> null
     * 
     * Logic:
     *      prev
     *      while node n in the list where n-> next is not null
     *      next = node.next
     *      node.next = prev
     *      prev = node
     *      node = next
     * 
     *      stops when node_next is null so n is the last node
     *      n.next = prev
     *      head = node
     * 
     *      case: empty list then return head
     *      case: one element retur head
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * 
     */
    ListNode* reverse(ListNode *head) {
        ListNode* result = head;

        // empty or list of one case
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr->next != nullptr){
            // save
            ListNode* next = curr->next;
            // swap
            curr->next = prev;
            
            // increment
            prev = curr;
            curr = next; 
        }

        curr->next = prev;

        return curr;
    }
};